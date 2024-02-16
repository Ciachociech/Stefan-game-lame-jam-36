#include <window/WindowInstance.h>

int main()
{
    window::WindowInstance instance(1280, 720, "SFML Template");
    instance.setFrameRate(60);
    return instance.loop();
}