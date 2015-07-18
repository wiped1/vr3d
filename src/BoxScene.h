#pragma once

class BoxScene
{
/* private members */
private:
    std::vector<Node*> nodes;
/* public functions */
public:
    BoxScene();
    Node* addNode(Node *node);
    void removeNode(const Node& node);
    void setup();
    void update();
    void draw();
    ~BoxScene();
/* private functions */
private:
};
