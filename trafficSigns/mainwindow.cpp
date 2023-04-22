#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	frameCounter = 0;
	paused = false;
	numSides = ui->numSides->value();
	findType = 0;
	aspectRatio.width = ui->horizAspect->text().toInt();
	aspectRatio.height = ui->vertAspect->text().toInt();
	minSize = ui->minSize->text().toInt();
	maxSize = ui->maxSize->text().toInt();
	sizeStep = ui->step->text().toInt();
	rotation = ui->rotation->text().toInt();
	shapeLimit = ui->shapeLimit->value();
	voteReq = ui->voteReq->value();
	writer = cv::VideoWriter();
	saveAsVideo = ui->saveAsVideo->isChecked();

	connect(ui->openCVView, SIGNAL(frameCaptured()), this, SLOT(newFrame()));
	//loadImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadVideo()
{
	sf.setSeenBefore(true);

	QString fileName = QFileDialog::getOpenFileName(this, tr("Open video"));
	if(fileName.isNull()) {
		return;
	}
	ui->openCVView->startCapture(fileName, 30, false);
	ui->playPauseBtn->setEnabled(true);
	ui->goBtn->setEnabled(false);
	frameCounter = 0;
}

void MainWindow::loadImage()
{	
	ui->openCVView->pauseCapture();

	sf.setSeenBefore(false);

	QString fileName = QFileDialog::getOpenFileName(this, tr("Open image"));
	if(fileName.isNull()) {
		return;
	}
	ui->openCVView->loadImage(fileName);
	//ui->openCVView->loadImage("speedLimit.png");
	ui->playPauseBtn->setEnabled(false);
	ui->goBtn->setEnabled(true);
	//this->originalImage = ui->openCVView->getImage().clone();
	ui->openCVView->resumeCapture();
}

void MainWindow::togglePause()
{
	if(paused) {
		ui->openCVView->resumeCapture();
		ui->playPauseBtn->setText(QString("Pause"));
	} else {
		ui->openCVView->pauseCapture();
		ui->playPauseBtn->setText(QString("Resume"));
	}
	paused = !paused;
}

void MainWindow::newFrame()
{
	//consoleWrite("Loaded new frame.");
	if(!ui->openCVView->isOpened() && this->originalImage.empty()) {
		this->originalImage = ui->openCVView->getImage().clone();
	}

	Mat image = ui->openCVView->getImage();
	Mat gray(image.rows, image.cols, CV_8UC1);

	// Convert to grayscale
	cv::cvtColor(image, gray, CV_BGR2GRAY);
	//consoleWrite("Converted to grayscale.");

	sf.setImage(gray);

	std::vector<foundShape> bestShapes;
	if(findType == 0) {
		bestShapes = sf.findRegPolygons(this->numSides, this->minSize, this->maxSize, this->shapeLimit, this->voteReq, this->sizeStep, this->rotation);

		cv::Scalar color;
		int rotation;
		switch(this->numSides) {
		case 3:
			color = cv::Scalar(255, 0, 0);
			rotation = -90+this->rotation;
			break;
		case 4:
			color = cv::Scalar(0, 255, 255);
			rotation = 45+this->rotation;
			break;
		case 8:
			color = cv::Scalar(0, 0, 255);
			rotation = 22.5+this->rotation;
			break;
		default:
			color = cv::Scalar(255, 0, 255);
			rotation = this->rotation;
		}

		// Draw results:
		for(unsigned int i = 0; i < bestShapes.size(); i++) {
			//cv::circle(image, bestShapes[i].getPosition(), bestShapes[i].getSize(), cv::Scalar(0, 255, 0), 2);

			float radius = bestShapes[i].getSize()/cos(M_PI/this->numSides); // Size is defining the apothem, so this must be converted to a radius before drawing.
			cvUtils::drawRegPolygon(image, this->numSides, radius, bestShapes[i].getPosition(), rotation, color, 2);
		}
	} else if(findType == 1) {
		bestShapes = sf.findRectangles(this->aspectRatio, this->minSize, this->maxSize, this->shapeLimit, this->voteReq, this->sizeStep, 10);

		Mat signTemplate = cv::imread("template25real.jpg");
		Mat smallTemplate;
		Mat correlationResult;
		float correlation = 0;

		// Draw results:
		for(unsigned int i = 0; i < bestShapes.size(); i++) {

			int height = cvUtils::round(bestShapes[i].getSize()*((float)aspectRatio.width/(float)aspectRatio.height));
			int width = bestShapes[i].getSize();

			// Run through each possible sign and do a simple template matching (rough code for demo purposes only):
			if(ui->useCCOR->isChecked() && bestShapes[i].getPosition().y-height/2 >= 0 && bestShapes[i].getPosition().y+height/2+1 > bestShapes[i].getPosition().y-height/2 && bestShapes[i].getPosition().y+height/2 <= image.rows && bestShapes[i].getPosition().x-width/2 >= 0 && bestShapes[i].getPosition().x+width/2+1 > bestShapes[i].getPosition().x-width/2 && bestShapes[i].getPosition().x+width/2 <= image.cols) {
				cv::resize(signTemplate, smallTemplate, cv::Size(width, height));
				cv::matchTemplate(image(cv::Range(bestShapes[i].getPosition().y-height/2, bestShapes[i].getPosition().y+height/2), cv::Range(bestShapes[i].getPosition().x-width/2, bestShapes[i].getPosition().x+width/2)), smallTemplate, correlationResult, CV_TM_CCORR_NORMED);
				correlation = correlationResult.at<float>(0,0);
			}

			if(correlation > 0.9 || !ui->useCCOR->isChecked()) {
				cv::Point upperLeft = cv::Point(bestShapes[i].getPosition().x-width/2, bestShapes[i].getPosition().y-height/2);
				cv::Point lowerRight = cv::Point(bestShapes[i].getPosition().x+width/2, bestShapes[i].getPosition().y+height/2);
				cv::rectangle(image, upperLeft, lowerRight, cv::Scalar(0, 255, 0), 2);
				//cv::circle(image, bestShapes[i].getPosition(), 3, cv::Scalar(0, 255, 0), -1);
				//consoleWrite(QString("Drawing sign at (%1, %2)").arg(bestShapes[i].getPosition().x).arg(bestShapes[i].getPosition().y));
			} else {
				consoleWrite(QString("Discarding sign due to too low correlation (%1)").arg(correlation));
			}
		}
	}

	if(saveAsVideo) {
		if(!writer.isOpened()) {
			openWriter();
		}
		writer << image;
	}

	ui->openCVView->updateDisplay();
	//consoleWrite("Done.");

	ui->statusBar->showMessage(QString("Frame: %1").arg(frameCounter++));
}

void MainWindow::consoleWrite(QString message)
{
	message = QString("%1: %2").arg(QTime::currentTime().toString("hh:mm:ss.zzz")).arg(message);
	QByteArray ba = message.toLocal8Bit();
	const char *string = ba.data();
	printf("%s\n", string);
	ui->outputConsole->appendPlainText(message);
}


void MainWindow::on_numSides_editingFinished()
{
	this->numSides = ui->numSides->value();
	consoleWrite("Number of sides set.");
}

void MainWindow::on_regPolyRadio_toggled(bool enabled)
{
	if(enabled) {
		ui->horizAspect->setEnabled(false);
		ui->vertAspect->setEnabled(false);
		ui->numSides->setEnabled(true);
		this->findType = 0;
		consoleWrite(QString("Looking for regular polygons with %1 sides.").arg(numSides));
	}
}

void MainWindow::on_rectRadio_toggled(bool enabled)
{
	if(enabled) {
		ui->horizAspect->setEnabled(true);
		ui->vertAspect->setEnabled(true);
		ui->numSides->setEnabled(false);
		this->findType = 1;
		consoleWrite(QString("Looking for rectangles with an aspect ratio of %1:%2.").arg(this->aspectRatio.width).arg(this->aspectRatio.height));
	}
}

void MainWindow::on_horizAspect_editingFinished()
{
	aspectRatio.width = ui->horizAspect->text().toInt();
	consoleWrite(QString("Aspect ratio is now %1:%2").arg(this->aspectRatio.width).arg(this->aspectRatio.height));
}

void MainWindow::on_vertAspect_editingFinished()
{
	aspectRatio.height = ui->vertAspect->text().toInt();
	consoleWrite(QString("Aspect ratio is now %1:%2").arg(this->aspectRatio.width).arg(this->aspectRatio.height));
}

void MainWindow::on_minSize_editingFinished()
{
	minSize = ui->minSize->text().toInt();
	consoleWrite("Minimum size set.");
}

void MainWindow::on_maxSize_editingFinished()
{
	maxSize = ui->maxSize->text().toInt();
	consoleWrite("Maximum size set.");
}

void MainWindow::on_step_editingFinished()
{
	sizeStep = ui->step->text().toInt();
	consoleWrite("Step size set.");
}

void MainWindow::on_shapeLimit_editingFinished()
{
	this->shapeLimit = ui->shapeLimit->value();
	consoleWrite("Shape limit set.");
}

void MainWindow::on_rotation_editingFinished()
{
	this->rotation = ui->rotation->text().toInt();
	consoleWrite("Base rotation set.");
}

void MainWindow::on_voteReq_editingFinished()
{
	this->voteReq = ui->voteReq->value();
	consoleWrite("Minimum vote requirement set.");
}

void MainWindow::on_goBtn_clicked()
{
	//cv::imshow("img", originalImage);
	ui->openCVView->getImage() = originalImage.clone();
	newFrame();
}

void MainWindow::on_saveAsVideo_stateChanged()
{
	saveAsVideo = ui->saveAsVideo->isChecked();
	if(saveAsVideo && writer.isOpened()) { // If a writer already exists, restart it, since a new recording has now been requested.
		openWriter();
	}
}

bool MainWindow::openWriter()
{
	QString filename = QString("output_%1.avi").arg(QDateTime::currentDateTime().toTime_t());
	return writer.open((const char *)filename.toAscii(), CV_FOURCC('D','I','V','X'), ui->openCVView->getCaptureProperty(CV_CAP_PROP_FPS), cv::Size(ui->openCVView->getImage().cols, ui->openCVView->getImage().rows));
}
