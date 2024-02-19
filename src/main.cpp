#include <window/WindowInstance.h>

int main()
{
    window::WindowInstance instance(800, 480, "Stefan: against beholders, logic and any quality");
    instance.setFrameRate(60);
    return instance.loop();
}