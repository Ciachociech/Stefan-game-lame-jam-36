#ifndef WINDOW_WINDOWINSTANCE_H_
#define WINDOW_WINDOWINSTANCE_H_

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

#include <audio/Sound.h>
#include <audio/SoundBuffer.h>
#include <game/Gameover.h>
#include <game/Scene.h>
#include <game/Stage.h>
#include <game/Titlescreen.h>
#include <window/JoystickInput.h>
#include <window/KeyboardInput.h>

namespace window {

enum class ProgramState { none, titlescreen, stage, gameover };

class WindowInstance {
private:
	sf::RenderWindow window;
	ProgramState state;

	JoystickInput joystick;
	KeyboardInput keyboard;

	std::unique_ptr<game::Stage> stage;
	game::Gameover gameover;
	game::Titlescreen titlescreen;

	audio::Sound sound;
	audio::SoundBuffer soundComplete;
	audio::SoundBuffer soundUniversal;

	int waitFrames = 0;
	int stageCounter = 1;
public:
	WindowInstance(int width, int height, std::string name);

	void setFrameRate(int frames);

	int loop();
};

}

#endif