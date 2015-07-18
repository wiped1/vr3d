#pragma once

class Node
{
    virtual void setup() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual ~Node() { }
};
