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
	sf::Vector2f velocity;
public:
	MainPlayer();
	virtual ~MainPlayer();

	void processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput);
	void update() override;

	const sf::Vector2f& getVelocity();
	void resolveCollisionWithWall(const sf::FloatRect& wallHitbox);
};

}

#endif // !GAME_MAINPLAYER_H_
