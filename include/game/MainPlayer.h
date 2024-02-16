#ifndef GAME_MAINPLAYER_H_
#define GAME_MAINPLAYER_H_

#include <drawable/Sprite.h>
#include <window/JoystickInput.h>
#include <window/KeyboardInput.h>

namespace game {

class MainPlayer {
private:
	drawable::Sprite sprite;
	drawable::Texture texture;
public:
	MainPlayer();

	void processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput);
	void update();

	const drawable::Sprite& getSprite();
};

}

#endif // !GAME_MAINPLAYER_H_
