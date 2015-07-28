#include "ofApp.h"

#include <iostream>
#include <OffAxisCamera.h>
#include <Node.h>

class BoxyBox : public Node
{
private:
    ofVec3f pos;
    ofColor color;
public:
    BoxyBox(ofVec3f pos, ofColor color) : pos(pos), color(color)
    {

    }

    virtual void setup()
    {

    }

    virtual void update()
    {

    }

    virtual void render()
    {
        ofSetColor(color);
        ofDrawBox(pos, 5.0); // x, y, z, size
    }
};


void ofApp::setup()
{
    double cameraSize = 15;
    double aspectRatio = static_cast<double>(ofGetWidth()) / ofGetHeight(); // 1024/768 = 1.(3)
    ofVec3f topLeft(-cameraSize * aspectRatio, cameraSize, 0.0); // -15 * 1.(3) = -19,5, 15
    ofVec3f botLeft(-cameraSize * aspectRatio, -cameraSize, 0.0); // -15 * 1.(3) = -19.5, -15
    ofVec3f botRight(cameraSize * aspectRatio, -cameraSize, 0.0); // 15 * 1.(3) = 19.5, -15
    cam = dynamic_cast<OffAxisCamera *>(scene.addNode(new OffAxisCamera(
            topLeft, botLeft, botRight)));
    cam->setPosition(ofVec3f(0.0, 0.0, 50.0f));

    scene.addNode(new BoxyBox(ofVec3f(0.0, 0.0, 0.0), ofColor::red));
    scene.addNode(new BoxyBox(ofVec3f(0.0, 0.0, -5.0), ofColor::yellow));
    scene.addNode(new BoxyBox(ofVec3f(-10.0, -10.0, -10.0), ofColor::green));
    scene.addNode(new BoxyBox(ofVec3f(10.0, 10.0, 10.0), ofColor::blue));

    /* when exporting from blender make sure to export with correct handedness
     * for of which has right hand coordinate system correct export would be
     * -Z up, and Y forward
     */
    model.loadModel("devbot.3ds", true);
}

void ofApp::update()
{
    scene.update();
    model.setPosition(0.0f, 5.0f, 0.0f);
}

void ofApp::draw()
{
    scene.render(cam);
    cam->begin();
    model.enableMaterials();
    model.setScale(0.01f, 0.01f, 0.01f);
    model.draw(ofPolyRenderMode::OF_MESH_FILL);
    cam->end();
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
