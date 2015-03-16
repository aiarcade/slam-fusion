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

     inImage= cv::imread(name, CV_LOAD_IMAGE_GRAYSCALE);
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

    //vl_liopdesc_process(liop,features,) ;
   /* vl_covdet(linImage,'descriptor', 'liop');
    for(int i=0;i<dimension;i++)
        if(features[i]>0)
          qDebug()<<features[i];*/
    VlCovDet * covdet = vl_covdet_new(VL_COVDET_METHOD_HESSIAN) ;
    // set various parameters (optional)
    vl_covdet_set_first_octave(covdet, -1) ; // start by doubling the image resolution
    vl_covdet_set_octave_resolution(covdet, octaveResolution) ;
    vl_covdet_set_peak_threshold(covdet, peakThreshold) ;
    vl_covdet_set_edge_threshold(covdet, edgeThreshold) ;
    // process the image and run the detector
    vl_covdet_put_image(covdet, image, numRows, numCols) ;
    vl_covdet_detect(covdet) ;
    // drop features on the margin (optional)
    vl_covdet_drop_features_outside (covdet, boundaryMargin) ;
    // compute the affine shape of the features (optional)
    vl_covdet_extract_affine_shape(covdet) ;
    // compute the orientation of the features (optional)
    vl_covdet_extract_orientations(covdet) ;
    // get feature frames back
    vl_size numFeatures = vl_covdet_get_num_features(covdet) ;
    VlCovDetFeature const * feature = vl_covdet_get_features(covdet) ;



}
