#include <Scene.h>

#include <Node.h>
#include <Camera.h>

class OffAxisCamera : public Node, public Camera
{
/* public member functions */
public:
    OffAxisCamera();
    virtual void setup();
    virtual void update();
    virtual void render();
    virtual void begin();
    virtual void end();
    virtual ~OffAxisCamera();
/* private member functions */
private:
};
