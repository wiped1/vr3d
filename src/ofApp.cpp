#include "ofApp.h"

#include <OffAxisCamera.h>

//--------------------------------------------------------------
void ofApp::setup() {
    Camera *cam = dynamic_cast<Camera *>(scene.addNode(new OffAxisCamera()));
}

void ofApp::update() {

}

void ofApp::draw() {
    scene.render(cam);
}

void ofApp::keyPressed(int key) {

}

void ofApp::keyReleased(int key) {

}

void ofApp::mouseMoved(int x, int y ) {

}

void ofApp::mouseDragged(int x, int y, int button) {

}

void ofApp::mousePressed(int x, int y, int button) {

}

void ofApp::mouseReleased(int x, int y, int button) {

}

void ofApp::windowResized(int w, int h) {

}

void ofApp::gotMessage(ofMessage msg) {

}

void ofApp::dragEvent(ofDragInfo dragInfo) {

}
