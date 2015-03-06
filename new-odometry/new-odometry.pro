#-------------------------------------------------
#
# Project created by QtCreator 2015-03-03T13:49:42
#
#-------------------------------------------------

QT       += core gui
INCLUDEPATH +=/usr/include/opencv
LIBS += -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_flann
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = new-odometry
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    featuredetector.cpp

HEADERS  += widget.h \
    featuredetector.h

FORMS    += widget.ui

unix:!macx:!symbian: LIBS += -L/opt/vlfeat/bin/glnxa64/ -lvl

INCLUDEPATH += /opt/vlfeat
DEPENDPATH += /opt/vlfeat
