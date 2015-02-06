#ifndef GLWIDGET_H
 #define GLWIDGET_H

#include <QtGui>
#include <QGLWidget>
#include <QImage>
#include <QDebug>

 class QGLShaderProgram;

 class GLWidget : public QGLWidget
 {
     Q_OBJECT

 public:
     GLWidget(QWidget *parent = 0, QGLWidget *shareWidget = 0);
     ~GLWidget();

     QSize minimumSizeHint() const;
     QSize sizeHint() const;
     void rotateBy(int xAngle, int yAngle, int zAngle);
     void setClearColor(const QColor &color);
     void updateTexture(QImage *);

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
 #ifdef QT_OPENGL_ES_2
     QGLShaderProgram *program;
 #endif
 };

 #endif
