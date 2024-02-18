#include <window/WindowInstance.h>

namespace window {
	
WindowInstance::WindowInstance(int width, int height, std::string name) : window(sf::VideoMode(width, height), name), state(ProgramState::none), stage(), gameover(&window) {
    sf::Image icon;
    icon.loadFromFile("assets/sprites/WIP32x32.png");
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

        this->window.clear(sf::Color(0, 0, 0, 255));

        switch (this->state) {
            /*
            add cases which are connected with ProgramStates
            */
            case ProgramState::none: {
                state = ProgramState::stage;
                stage = std::make_unique<game::Stage>(&window);
                break;
            }
            case ProgramState::stage: {
                stage->processInput(keyboardInput, joystickInput);
                if (!stage->update()) {
                    state = ProgramState::gameover;
                }
                stage->render();
                break;
            }
            case ProgramState::gameover: {
                gameover.processInput(keyboardInput, joystickInput);
                if (!gameover.update()) {
                    stage.reset();
                    state = ProgramState::none;
                }
                if (stage) { stage->render(); }
                gameover.render();
                break;
            }
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