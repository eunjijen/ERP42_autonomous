#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <stdio.h>
#include <math.h>
#include <vector>
#include <QMainWindow>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "shapefinder.h"

typedef cv::Mat Mat;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
	void consoleWrite(QString message);
	float round(float d);
	bool inImage(cv::Point point, cv::Size imageSize);
	bool openWriter();

    Ui::MainWindow *ui;
	shapeFinder sf;
	int frameCounter;
	bool paused;
	int numSides;
	int findType;
	cv::Size aspectRatio;
	int minSize;
	int maxSize;
	int sizeStep;
	int shapeLimit;
	int rotation;
	int voteReq;
	Mat originalImage;
	cv::VideoWriter writer;
	bool saveAsVideo;

private slots:
	void loadVideo();
	void loadImage();
	void togglePause();
	void newFrame();
	void on_numSides_editingFinished();
	void on_regPolyRadio_toggled(bool enabled);
	void on_rectRadio_toggled(bool enabled);
	void on_horizAspect_editingFinished();
	void on_vertAspect_editingFinished();
	void on_minSize_editingFinished();
	void on_maxSize_editingFinished();
	void on_step_editingFinished();
	void on_shapeLimit_editingFinished();
	void on_rotation_editingFinished();
	void on_voteReq_editingFinished();
	void on_goBtn_clicked();
	void on_saveAsVideo_stateChanged();
};

#endif // MAINWINDOW_H
