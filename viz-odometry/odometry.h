#ifndef ODOMETRY_H
#define ODOMETRY_H

#include <QObject>
#include "viso_stereo.h"
#include "matrix.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>

#include <viso_stereo.h>
#include <png++/png.hpp>
#include <QPixmap>
#include <QRgb>

class Odometry : public QObject
{
    Q_OBJECT
public:
    explicit Odometry(QObject *parent = 0);
    void findOdometry();
    QImage *getOrgLeftImage();
private:
    QImage leftImage;
    QImage rightImage;
    
signals:
    
public slots:
    
};

#endif // ODOMETRY_H
