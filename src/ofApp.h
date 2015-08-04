#pragma once

#include "ofMain.h"
#include "ofxFaceTracker.h"
#include "ofxAssimpModelLoader.h"
#include "ofxUI.h"

#include <OffAxisCamera.h>
#include <GridBox.h>

class ofApp : public ofBaseApp
{
/* private members */
private:
    const double CAMERA_SIZE = 15;

    OffAxisCamera cam;
    ofVideoGrabber videoGrabber;
    ofxFaceTracker tracker;
    ofxAssimpModelLoader model;
    GridBox gridBox;
    ofLight directionalLight;
    ofVec2f trackerOffset;

    /* gui */
    ofTrueTypeFont arial;
    ofxUICanvas *gui;
    bool trackingEnabled;
    bool showTracker;
    ofxUI2DPad *camXY;
    float camZ;
    float trackerSensitivityX;
    float trackerSensitivityY;
    float trackerSensitivityZ;
    float modelsZPosition;
    float modelsSeparation;
    float gridBoxDepth;

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

    /* user defined function */
    void exit();
    void setupGui();
    void guiEvent(ofxUIEventArgs& e);

/* private member functions */
private:
    void setupScene(int width, int height);
};
