#include "featuredetector.h"


FeatureDetector::FeatureDetector(QObject *parent) :
    QObject(parent)
{

    liop = vl_liopdesc_new_basic (sideLength);
    dimension = vl_liopdesc_get_dimension(liop) ;
    features = (float*)vl_malloc(sizeof(float) * dimension) ;

}

void FeatureDetector::readImage(char *name)
{

     inImage= cv::imread(name, CV_LOAD_IMAGE_COLOR);
     linImage= new float[inImage.rows*inImage.cols*inImage.channels()];
     // Convert image to one-dimensional array.
     int index=0;
    for (int i = 0; i < inImage.rows; ++i)
     {
       for (int j = 0; j < inImage.cols; ++j)
        {
         linImage[i]=inImage.at<unsigned char>(i, j);
         index++;
        }
     }
}

void FeatureDetector::computeFeatures()
{

    vl_liopdesc_process(liop,features,linImage) ;
    qDebug()<<features[0];
}
