#ifndef WINDOW_WINDOWINSTANCE_H_
#define WINDOW_WINDOWINSTANCE_H_

#include <string>

#include <SFML/Graphics.hpp>

#include <window/JoystickInput.h>
#include <window/KeyboardInput.h>

namespace window {

enum class ProgramState { none, /* add states like titlescreen, menu, game and gameover */ };

class WindowInstance {
private:
	sf::RenderWindow window;
	ProgramState state;

	JoystickInput joystick;
	KeyboardInput keyboard;

	int waitFrames = 0;
public:
	WindowInstance(int width, int height, std::string name);

	void setFrameRate(int frames);

	int loop();
};

}

#endif