#ifndef GLPLOTWIDGET_H
 #define GLPLOTWIDGET_H

#include <QtGui>
#include <QGLWidget>
#include <QImage>
#include <QDebug>
#include "matrix.h"

 class QGLShaderProgram;

 class GLPlotWidget : public QGLWidget
 {
     Q_OBJECT

 public:
     GLPlotWidget(QWidget *parent = 0, QGLWidget *shareWidget = 0);
     ~GLPlotWidget();

     QSize minimumSizeHint() const;
     QSize sizeHint() const;
     void rotateBy(int xAngle, int yAngle, int zAngle);
     void setClearColor(const QColor &color);
     void updatePlot(Matrix *);

 signals:
     void clicked();

 protected:
     void initializeGL();
     void paintGL();
     void resizeGL(int width, int height);
     void mousePressEvent(QMouseEvent *event);
     void mouseMoveEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);

 private:
     void makeObject();
     int leftImageWidth;
     int leftImageHeight;

     QColor clearColor;
     QPoint lastPos;
     int xRot;
     int yRot;
     int zRot;
     GLuint textures[6];
     QVector<QVector3D> vertices;
     QVector<QVector2D> texCoords;
     Matrix prevPos;
     Matrix currentPos;
     Matrix *eye;
 #ifdef QT_OPENGL_ES_2
     QGLShaderProgram *program;
 #endif
 };

 #endif
