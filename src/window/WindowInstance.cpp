#include <window/WindowInstance.h>

namespace window {
	
WindowInstance::WindowInstance(int width, int height, std::string name) : window(sf::VideoMode(width, height), name), state(ProgramState::none), stage(), gameover(&window), titlescreen(&window), sound("sound"), soundComplete("assets/audio/complete.wav"),
                                                                          soundUniversal("assets/audio/universal.wav") {
    sf::Image icon;
    icon.loadFromFile("assets/sprites/b4-logo.png");
    this->window.setIcon(32, 32, icon.getPixelsPtr());

    sound.setBuffer(soundUniversal);
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
            case ProgramState::none: {
                state = ProgramState::titlescreen;
                break;
            }
            case ProgramState::titlescreen: {
                this->window.clear(sf::Color(0, 0, 0, 255));

                titlescreen.processInput(keyboardInput, joystickInput);
                if (titlescreen.update()) {
                    sound.play();
                    state = ProgramState::stage;
                    stage = std::make_unique<game::Stage>(&window, stageCounter);
                }
                titlescreen.render();
                
                break;
            }
            case ProgramState::stage: {
                this->window.clear(sf::Color(118, 168, 204, 255));

                stage->processInput(keyboardInput, joystickInput);
                switch (stage->update()) {
                    case 1: {
                        sound.setBuffer(soundComplete);
                        sound.play();

                        if (stageCounter < 3) {
                            stage.reset();
                            stage = std::make_unique<game::Stage>(&window, ++stageCounter);
                        }
                        else {
                            state = ProgramState::gameover;
                        }
                        break;
                    }
                    case -1: {
                        state = ProgramState::gameover;
                        break;
                    }
                }
                stage->render();

                break;
            }
            case ProgramState::gameover: {
                this->window.clear(sf::Color(118, 168, 204, 255));

                gameover.processInput(keyboardInput, joystickInput);
                if (gameover.update()) {
                    stage.reset();
                    stageCounter = 1;
                    state = ProgramState::none;
                    stage = std::make_unique<game::Stage>(&window, stageCounter);
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