#include <window/WindowInstance.h>

int main()
{
    window::WindowInstance instance(800, 480, "bulonais-4");
    instance.setFrameRate(60);
    return instance.loop();
}