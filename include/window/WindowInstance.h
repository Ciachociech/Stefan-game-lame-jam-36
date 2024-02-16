#ifndef WINDOW_WINDOWINSTANCE_H_
#define WINDOW_WINDOWINSTANCE_H_

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

//#include <game/Scene.h>
#include <game/Stage.h>
#include <window/JoystickInput.h>
#include <window/KeyboardInput.h>

namespace window {

enum class ProgramState { none, stage /* add states like titlescreen, menu, game and gameover */ };

class WindowInstance {
private:
	sf::RenderWindow window;
	ProgramState state;

	JoystickInput joystick;
	KeyboardInput keyboard;

	std::unique_ptr<game::Stage> stage;

	int waitFrames = 0;
public:
	WindowInstance(int width, int height, std::string name);

	void setFrameRate(int frames);

	int loop();
};

}

#endif