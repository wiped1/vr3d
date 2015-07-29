#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include <OffAxisCamera.h>
#include <GridBox.h>

class ofApp : public ofBaseApp
{
/* private members */
private:
    OffAxisCamera cam;
    ofxAssimpModelLoader model;
    GridBox gridBox;
    ofImage roomTexture;
    ofLight directionalLight;

/* public member functions */
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
};
