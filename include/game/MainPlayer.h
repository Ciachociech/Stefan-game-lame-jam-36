#ifndef GAME_MAINPLAYER_H_
#define GAME_MAINPLAYER_H_

#include <game/SolidObject.h>

#include <drawable/Sprite.h>
#include <window/JoystickInput.h>
#include <window/KeyboardInput.h>

namespace game {

class MainPlayer : public SolidObject {
private:
public:
	MainPlayer();

	void processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput);
	void update() override;

	const drawable::Sprite& getSprite();
};

}

#endif // !GAME_MAINPLAYER_H_
