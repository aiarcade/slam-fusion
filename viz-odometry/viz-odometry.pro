#-------------------------------------------------
#
# Project created by QtCreator 2015-02-05T13:42:49
#
#-------------------------------------------------

QT       += core gui widgets opengl

INCLUDEPATH +=/usr/include/qwt/
LIBS += -lqwt
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = viz-odometry
TEMPLATE = app


SOURCES += main.cpp\
        vizwindow.cpp \
    glwidget.cpp \
    viso_stereo.cpp \
    viso_mono.cpp \
    viso.cpp \
    triangle.cpp \
    reconstruction.cpp \
    matrix.cpp \
    matcher.cpp \
    filter.cpp \
    odometry.cpp \
    odometryengine.cpp \
    glplotwidget.cpp \
    plotwidget.cpp

HEADERS  += vizwindow.h \
    glwidget.h \
    viso_stereo.h \
    viso_mono.h \
    viso.h \
    triangle.h \
    timer.h \
    reconstruction.h \
    matrix.h \
    matcher.h \
    filter.h \
    odometry.h \
    odometryengine.h \
    glplotwidget.h \
    plotwidget.h

FORMS    += vizwindow.ui
