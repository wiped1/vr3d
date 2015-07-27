#include "OffAxisCamera.h"

#include <chrono>
#include <cmath>

OffAxisCamera::OffAxisCamera(ofVec3f topLeft, ofVec3f botLeft, ofVec3f botRight)
    : topLeft(topLeft), botLeft(botLeft), botRight(botRight)
{
    //ctor
}

OffAxisCamera::~OffAxisCamera()
{
    //dtor
}

void OffAxisCamera::setup()
{

}

void OffAxisCamera::update()
{
    unsigned long mili =
        std::chrono::system_clock::now().time_since_epoch() /
        std::chrono::milliseconds(1);
    double damping = 10;
    setPosition(std::cos(mili * M_PI/180 / damping) * 10.0,
                     std::sin(mili * M_PI/180 / damping) * 10.0, cam.getPosition().z);
    cam.setupOffAxisViewPortal(topLeft, botLeft, botRight);
}

void OffAxisCamera::render()
{
    // do nothing
}

void OffAxisCamera::begin()
{
    cam.begin();
}

void OffAxisCamera::end()
{
    cam.end();
}

void OffAxisCamera::setPosition(double x, double y, double z)
{
    cam.setPosition(x, y, z);
}

void OffAxisCamera::setPosition(ofVec3f position)
{
    setPosition(position.x, position.y, position.z);
}

ofVec3f OffAxisCamera::getPosition()
{
    return cam.getPosition();
}

