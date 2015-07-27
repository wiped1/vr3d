#pragma once

#include "ofMain.h"
#include <Scene.h>
#include <Node.h>
#include <Camera.h>

class OffAxisCamera : public Node, public Camera
{
/* private member variables */
private:
    ofCamera cam;
    ofVec3f topLeft;
    ofVec3f botLeft;
    ofVec3f botRight;
/* public member functions */
public:
    OffAxisCamera(ofVec3f topLeft, ofVec3f botLeft, ofVec3f botRight);
    virtual ~OffAxisCamera();
    virtual void setup();
    virtual void update();
    virtual void render();
    virtual void begin();
    virtual void end();
    void setPosition(double x, double y, double z);
    void setPosition(ofVec3f position);
    ofVec3f getPosition();
/* private member functions */
private:
};
