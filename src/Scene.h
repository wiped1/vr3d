#pragma once

#include <vector>
#include <Node.h>
#include <Camera.h>

class Scene
{
/* private members */
private:
    std::vector<Node *> nodes;
/* public member functions */
public:
    Scene();
    Node* addNode(Node *node);
    void removeNode(const Node *node);
    void setCamera(Camera *node);
    void setup();
    void update();
    void render(Camera *camera);
    ~Scene();
/* private member functions */
private:
};
