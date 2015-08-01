#pragma once

#include "ofMain.h"

class GridBox
{
/* private members */
private:
    /* point of origin */
    ofVec3f origin;
    /* width along the X+ axis  */
    double width;
    /* height along the Y+ axis */
    double height;
    /* plane division factor */
    double divisionFactor;

/* public functions */
public:
    GridBox() { }
    GridBox(ofVec3f origin, double width, double height, double divisionFactor);
    void draw(float depth);
};
