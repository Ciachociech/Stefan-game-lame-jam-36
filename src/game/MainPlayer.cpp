#include <game/MainPlayer.h>

namespace game {

MainPlayer::MainPlayer() : sprite("MainPlayer"), texture("assets/sprites/stefan-head2.png") {
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(400, 240));
	sprite.setOriginCenter();
}

void MainPlayer::processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) {
	//TODO
}

void MainPlayer::update() {
	//TODO
}

const drawable::Sprite& MainPlayer::getSprite() {
	return sprite;
}

}