#ifndef FEATUREDETECTOR_H
#define FEATUREDETECTOR_H

#include <QObject>
#include <QDebug>

#include <opencv2/opencv.hpp>
#include <vector>

extern "C" {
    #include "vl/generic.h"
    #include "vl/slic.h"
    #include <vl/liop.h>
}


class FeatureDetector : public QObject
{
    Q_OBJECT
public:
    explicit FeatureDetector(QObject *parent = 0);
    void readImage(char * name);
    void computeFeatures();
private:
    cv::Mat inImage;
    float * linImage;
    vl_size sideLength = 41 ;
    VlLiopDesc * liop;
    vl_size dimension;
    float * features;

signals:
    
public slots:
    
};

#endif // FEATUREDETECTOR_H
//#include <vl/liop.h>
//// Create a new object instance (these numbers corresponds to parameter
//// values proposed by authors of the paper, except for 41)
//vl_size sideLength = 41 ;
//VlLiopDesc * liop = vl_liopdesc_new_basic (sideLength);
//// allocate the descriptor array
//vl_size dimension = vl_liopdesc_get_dimension(liop) ;
//float * desc = vl_malloc(sizeof(float) * dimension) ;
//// compute descriptor from a patch (an array of length sideLegnth *
//// sideLength)
//vl_liopdesc_process(liop, desc, patch) ;
//// delete the object
//vl_liopdesc_delete(liop) ;
