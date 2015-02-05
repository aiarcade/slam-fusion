#ifndef ODOMETRYENGINE_H
#define ODOMETRYENGINE_H

#include <QThread>
#include <odometry.h>
#include <QImage>
class OdometryEngine : public QThread
{
    Q_OBJECT
public:
    OdometryEngine();
    QImage *getLeftImage();
private:
   Odometry *stOdo;
   QImage leftImage;
   void run();


    
signals:
    
public slots:
    
};

#endif // ODOMETRYENGINE_H
