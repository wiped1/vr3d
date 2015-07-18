#pragma once

class Node
{
public:
    virtual void setup() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual ~Node() { }
};
