#include "ofApp.h"

#include <iostream>
#include <OffAxisCamera.h>

void ofApp::setupGui() {
    gui->addToggle("FULLSCREEN", false);
    gui->addToggle("ENABLE FACE TRACKING", true);
    gui->addToggle("SHOW TRACKER", false);
    gui->addSpacer();
    gui->addSlider("CAMERA Z", 10.0, 100.0, &camZ);
    camXY = gui->add2DPad("CAMERA X, Y", ofPoint(-10, 10), ofPoint(10, -10), ofPoint(0, 0));
    camXY->setIncrement(0.1);
    gui->addSpacer();

    gui->addSlider("TRACKER X SENSITIVITY", 0.0, 1.0, &trackerSensitivityX);
    gui->addSlider("TRACKER Y SENSITIVITY", 0.0, 1.0, &trackerSensitivityY);
    gui->addSlider("TRACKER Z SENSITIVITY", 0.0, 50.0, &trackerSensitivityZ);
    gui->addLabelButton("ADD TRACKER OFFSET", false);
    gui->addSpacer();

    gui->addSlider("MODELS Z POSITION", -20.0, 10.0, &modelsZPosition);
    gui->addSlider("MODELS SEPARATION", -50.0, 50.0, &modelsSeparation);
    gui->addSlider("GRIDBOX DEPTH", 0.0, 50.0, &gridBoxDepth);
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent, this, &ofApp::guiEvent);
    gui->loadSettings("settings.xml");
}

void ofApp::setupScene(int width, int height)
{
    /* setup camera */
    double aspectRatio = static_cast<double>(width) / height;
    ofVec3f topLeft (-CAMERA_SIZE * aspectRatio,  CAMERA_SIZE, 0.0);
    ofVec3f botLeft (-CAMERA_SIZE * aspectRatio, -CAMERA_SIZE, 0.0);
    ofVec3f botRight( CAMERA_SIZE * aspectRatio, -CAMERA_SIZE, 0.0);
    cam = OffAxisCamera(topLeft, botLeft, botRight);
    cam.setPosition(ofVec3f(0.0, 0.0, 50.0f));

    /* calculate grid box dimension */
    ofVec3f camWidthVec = botRight - botLeft;
    double camWidth = camWidthVec.length();
    gridBox = GridBox(ofVec3f(-CAMERA_SIZE * aspectRatio, -CAMERA_SIZE, 0.0f),
            camWidth, camWidth / aspectRatio, 8.0f);
}

void ofApp::setup()
{
    /* load model */
    if (model.loadModel("devbot.3ds", true)) {
        model.setScale(0.02f, 0.02f, 0.02f);
    } else {
        std::cerr << "Failed to load model." << std::endl;
    }

    /* set light */
    directionalLight.setDirectional();
    directionalLight.setOrientation(ofVec3f(180.0f, 0.0f, 0.0f));

    /* setup tracker */
    tracker.setup();
    std::vector<ofVideoDevice> devices = videoGrabber.listDevices();
    videoGrabber.setDeviceID(0);
    /* can crash the PSEye if not set to 60 */
    videoGrabber.setDesiredFrameRate(60);
    videoGrabber.initGrabber(320, 240);

    /* setup gui */
    gui = new ofxUICanvas();
    setupGui();

    setupScene(ofGetWidth(), ofGetHeight());
}

void ofApp::update()
{
    if (trackingEnabled) {
        videoGrabber.update();
        if (videoGrabber.isFrameNew()) {
            tracker.update(ofxCv::toCv(videoGrabber));
            const ofVec2f& trackerPos = tracker.getPosition();
            ofVec2f newCamPos((videoGrabber.getWidth()/2) - trackerPos.x,
                    (videoGrabber.getHeight()/2 - trackerPos.y));
            cam.setPosition(newCamPos.x * trackerSensitivityX,
                    newCamPos.y * trackerSensitivityY,
                    camZ - tracker.getScale() * trackerSensitivityZ);
        }
    } else {
        cam.setPosition(camXY->getScaledValue().x, camXY->getScaledValue().y, camZ);
    }

    /* add offset */
    cam.setPosition(cam.getPosition().x + trackerOffset.x,
            cam.getPosition().y + trackerOffset.y,
            cam.getPosition().z);
    cam.update();
}

void ofApp::draw()
{
    ofClear(0.0, 1.0);
//    ofEnableLighting();
    ofEnableDepthTest();

    /* draw camera feed */
    if (trackingEnabled && showTracker) {
        tracker.draw();
        videoGrabber.draw(0, 0);
    }

    cam.begin();
//    directionalLight.enable();
    ofSetColor(ofColor::yellow);
    model.setPosition(5.0f, -4.0f, modelsZPosition + modelsSeparation);
    model.draw(ofPolyRenderMode::OF_MESH_FILL);

    ofSetColor(ofColor::cyan);
    model.setPosition(0.0f, -4.0f, modelsZPosition);
    model.draw(ofPolyRenderMode::OF_MESH_FILL);

    ofSetColor(ofColor::magenta);
    model.setPosition(-5.0f, -4.0f, modelsZPosition - modelsSeparation);
    model.draw(ofPolyRenderMode::OF_MESH_FILL);

    ofSetColor(ofColor::white);
    gridBox.draw(gridBoxDepth);
//    directionalLight.disable();
    cam.end();

}

void ofApp::keyPressed(int key)
{
    switch (key) {
        case 'h':
        case 'H': {
            gui->toggleVisible();
            break;
        }
    }
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
    setupScene(w, h);
}

void ofApp::gotMessage(ofMessage msg)
{

}

void ofApp::dragEvent(ofDragInfo dragInfo)
{

}

void ofApp::exit()
{
    gui->saveSettings("settings.xml");
    delete gui;
}

void ofApp::guiEvent(ofxUIEventArgs &e)
{
    if (e.getName() == "FULLSCREEN")
    {
        ofxUIToggle* toggle = e.getToggle();
        ofSetFullscreen(toggle->getValue());
    }
    else if (e.getName() == "ENABLE FACE TRACKING")
    {
        ofxUIToggle* toggle = e.getToggle();
        trackingEnabled = toggle->getValue();
    }
    else if (e.getName() == "SHOW TRACKER")
    {
        ofxUIToggle* toggle = e.getToggle();
        showTracker = toggle->getValue();
    }
    else if (e.getName() == "ADD TRACKER OFFSET") {
        ofxUIButton *button = (ofxUIButton *)e.widget;
        if (button->getValue()) {
            trackerOffset = ofVec2f(cam.getPosition().x - trackerOffset.x,
                    cam.getPosition().y - trackerOffset.y);
        }
    }
}
