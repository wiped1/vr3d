#include "Scene.h"

#include <algorithm>
#include "ofMain.h"

Scene::Scene()
{
    //ctor
}

Scene::~Scene()
{
    for (Node *node : nodes) {
        delete node;
    }
}

Node * Scene::addNode(Node *node)
{
    /* std::vector::insert(iterator pos, const T& value returns iterator to
     * newly added element */
    return *nodes.insert(nodes.end(), node);
}

void Scene::removeNode(const Node *node)
{
    nodes.erase(std::find(nodes.begin(), nodes.end(), node));
}

void Scene::setup()
{
    for (Node *node : nodes) {
        node->setup();
    }
}

void Scene::update()
{
    for (Node *node : nodes) {
        node->update();
    }
}

void Scene::render(Camera *camera)
{
    ofBackground(0.0, 1.0);
    ofEnableDepthTest();
    camera->begin();
    for (Node *node : nodes) {
        node->render();
    }
    camera->end();
}
