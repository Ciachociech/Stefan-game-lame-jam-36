#ifndef GAME_MAINPLAYER_H_
#define GAME_MAINPLAYER_H_

#include <game/SolidObject.h>

#include <drawable/Sprite.h>
#include <window/JoystickInput.h>
#include <window/KeyboardInput.h>

namespace game {

class MainPlayer : public SolidObject {
private:
	drawable::Sprite* sprite;
public:
	MainPlayer();
	virtual ~MainPlayer();

	void processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput);
	void update() override;
};

}

#endif // !GAME_MAINPLAYER_H_
