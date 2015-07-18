#pragma once

class Camera
{
public:
    virtual void begin() = 0;
    virtual void end() = 0;
    virtual ~Camera() { }
};
