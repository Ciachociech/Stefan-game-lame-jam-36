#include <window/WindowInstance.h>

namespace window {
	
WindowInstance::WindowInstance(int width, int height, std::string name) : window(sf::VideoMode(width, height), name), state(ProgramState::none) {
    sf::Image icon;
    icon.loadFromFile("assets/sprites/stefan-head2.png");
    this->window.setIcon(32, 32, icon.getPixelsPtr());
}

int WindowInstance::loop() {
    while (this->window.isOpen())
    {
        std::vector<PressedKey> keyboardInput;
        std::vector<PressedButton> joystickInput;
        
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                this->window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                keyboardInput = this->keyboard.getInput();
            }
            if (event.type == sf::Event::JoystickButtonPressed || event.type == sf::Event::JoystickMoved) {
                joystickInput = this->joystick.getInput();
            }
        }

        switch (this->state) {
            /*
            add cases which are connected with ProgramStates
            */
            default: {
                break;
            }

        }

        this->window.display();
    }

    return 0;
}

void WindowInstance::setFrameRate(int frames) {
    this->window.setFramerateLimit(frames);
}

}