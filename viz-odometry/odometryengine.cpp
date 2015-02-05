#include "odometryengine.h"

OdometryEngine::OdometryEngine()

{
    stOdo=new Odometry();


}

QImage *OdometryEngine::getLeftImage()
{
    return stOdo->getOrgLeftImage();

}
void OdometryEngine::run()
{
     stOdo->findOdometry();

}
