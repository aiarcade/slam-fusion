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
Matrix * OdometryEngine::getPosition()
{
     return stOdo->getPosition();

}

void OdometryEngine::setDataPath(std::string path)
{
    stOdo->setDataPath(path);
}
