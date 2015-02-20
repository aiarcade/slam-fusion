#ifndef ODOMETRYENGINE_H
#define ODOMETRYENGINE_H

#include <QThread>
#include <odometry.h>
#include <QImage>
#include "matrix.h"
class OdometryEngine : public QThread
{
    Q_OBJECT
public:
    OdometryEngine();
    QImage *getLeftImage();
    Matrix *getPosition();
    void setDataPath(std::string);
private:
   Odometry *stOdo;
   QImage leftImage;
   Matrix *pose;
   std::string data_set_path;
   void run();


    
signals:
    
public slots:
    
};

#endif // ODOMETRYENGINE_H
