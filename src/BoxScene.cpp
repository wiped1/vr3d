#include "BoxScene.h"

BoxScene::BoxScene()
{
    //ctor
}

BoxScene::~BoxScene()
{
    for (Node *node : nodes) {
        delete node;
    }
}

Node* BoxScene::addNode(Node* node)
{
    /* std::vector::insert(iterator pos, const T& value returns iterator to
     * newly added element */
    return *nodes.insert(nodes.end(), node);
}

void BoxScene::removeNode(const Node* node)
{
    nodes.erase(std::find(nodes.begin(), nodes.end(), node));
}

void BoxScene::setup()
{
    for (Node *node : nodes) {
        node->setup();
    }
}

void BoxScene::update()
{
    for (Node* node : nodes) {
        node->update();
    }
}

void BoxScene::draw()
{
    for (Node* node : nodes) {
        node->draw();
    }
}
