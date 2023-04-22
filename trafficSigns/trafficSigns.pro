#-------------------------------------------------
#
# Project created by QtCreator 2011-11-10T14:53:18
#
#-------------------------------------------------

QT       += core gui

TARGET = trafficSigns
TEMPLATE = app


SOURCES += main.cpp\
		mainwindow.cpp \
    shapefinder.cpp \
    foundshape.cpp

HEADERS  += mainwindow.h \
    shapefinder.h \
    foundshape.h

FORMS    += mainwindow.ui

LIBS *= -lopencv_core \
		-lopencv_highgui \
		-lopencv_imgproc

VPATH = ../common/

include($${VPATH}opencvwidget.pri)
include($${VPATH}cvutilities.pri)




