#include "OffAxisCamera.h"

#include <chrono>
#include <cmath>

OffAxisCamera::OffAxisCamera(ofVec3f topLeft, ofVec3f botLeft, ofVec3f botRight)
    : topLeft(topLeft), botLeft(botLeft), botRight(botRight)
{
    cam.setNearClip(0.001);
}

void OffAxisCamera::update()
{
    cam.setupOffAxisViewPortal(topLeft, botLeft, botRight);
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

