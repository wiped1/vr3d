#pragma once

#include "ofMain.h"

class OffAxisCamera
{
/* private member variables */
private:
    ofCamera cam;
    ofVec3f topLeft;
    ofVec3f botLeft;
    ofVec3f botRight;

/* public member functions */
public:
    OffAxisCamera() { }
    OffAxisCamera(ofVec3f topLeft, ofVec3f botLeft, ofVec3f botRight);
    void update();
    void begin();
    void end();
    void setPosition(double x, double y, double z);
    void setPosition(ofVec3f position);
    void setFarFrustrum(ofVec3f topLeft, ofVec3f botLeft, ofVec3f botRight);
    ofVec3f getPosition();
};
