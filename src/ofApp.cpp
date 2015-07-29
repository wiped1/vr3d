#include "ofApp.h"

#include <iostream>
#include <OffAxisCamera.h>

void ofApp::setup()
{
    double cameraSize = 15;
    double aspectRatio = static_cast<double>(ofGetWidth()) / ofGetHeight();
    ofVec3f topLeft (-cameraSize * aspectRatio,  cameraSize, 0.0);
    ofVec3f botLeft (-cameraSize * aspectRatio, -cameraSize, 0.0);
    ofVec3f botRight( cameraSize * aspectRatio, -cameraSize, 0.0);
    cam = OffAxisCamera(topLeft, botLeft, botRight);
    cam.setPosition(ofVec3f(0.0, 0.0, 50.0f));

    if (model.loadModel("devbot.3ds", true)) {
        model.setScale(0.02f, 0.02f, 0.02f);
        model.setPosition(0.0f, 0.0f, -5.0f);
    } else {
        std::cerr << "Failed to load model." << std::endl;
    }

    directionalLight.setDirectional();
    directionalLight.setOrientation(ofVec3f(180.0f, 0.0f, 0.0f));

    ofVec3f camWidthVec = botRight - botLeft;
    double camWidth = camWidthVec.length();
    gridBox = GridBox(ofVec3f(-cameraSize * aspectRatio, -cameraSize, 0.0f),
            camWidth, camWidth / aspectRatio, 10.0f, 8.0f);
}

void ofApp::update()
{
    cam.update();
}

void ofApp::draw()
{
    ofClear(0.0, 1.0);
//    ofEnableLighting();
    ofEnableDepthTest();

    cam.begin();
//    directionalLight.enable();
    ofSetColor(ofColor::green);
    model.setPosition(0.0f, -2.0f, 0.0f);
    model.draw(ofPolyRenderMode::OF_MESH_FILL);

    ofSetColor(ofColor::red);
    model.setPosition(5.0f, -2.0f, 5.0f);
    model.draw(ofPolyRenderMode::OF_MESH_FILL);

    ofSetColor(ofColor::blue);
    model.setPosition(-5.0f, -2.0f, -5.0f);
    model.draw(ofPolyRenderMode::OF_MESH_FILL);

    ofSetColor(ofColor::white);
    gridBox.draw();
//    directionalLight.disable();
    cam.end();

}

void ofApp::keyPressed(int key)
{

}

void ofApp::keyReleased(int key)
{

}

void ofApp::mouseMoved(int x, int y )
{

}

void ofApp::mouseDragged(int x, int y, int button)
{

}

void ofApp::mousePressed(int x, int y, int button)
{

}

void ofApp::mouseReleased(int x, int y, int button)
{

}

void ofApp::windowResized(int w, int h)
{

}

void ofApp::gotMessage(ofMessage msg)
{

}

void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
