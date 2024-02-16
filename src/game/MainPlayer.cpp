#include <game/MainPlayer.h>

namespace game {

MainPlayer::MainPlayer() : SolidObject("MainPlayer", "assets/sprites/stefan-head2.png") {
	SolidObject::getSprite().setPosition(sf::Vector2f(400, 240));
	SolidObject::getSprite().setOriginCenter();
}

void MainPlayer::processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) {
	//TODO
}

void MainPlayer::update() {
	//TODO
}

const drawable::Sprite& MainPlayer::getSprite() {
	return SolidObject::getSprite();
}

}