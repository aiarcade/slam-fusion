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
#include <QImageWriter>
#include <QDebug>
class Odometry : public QObject
{
    Q_OBJECT
public:
    explicit Odometry(QObject *parent = 0);
    void findOdometry();
    QImage *getOrgLeftImage();
    Matrix *getPosition();
    void setDataPath(std::string);
private:
    QImage leftImage;
    QImage rightImage;
    Matrix pose ;
    std::string data_set_path;
    
signals:
    
public slots:
    
};

#endif // ODOMETRY_H
