#include <game/MainPlayer.h>

namespace game {

MainPlayer::MainPlayer() : SolidObject("MainPlayer", "assets/sprites/stefan-head2.png") {
	sprite = &SolidObject::getSprite();
	sprite->setPosition(sf::Vector2f(400, 240));
	sprite->setOriginCenter();
}

MainPlayer::~MainPlayer() {}

void MainPlayer::processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) {
	float moveX = 0;
	float moveY = 0;
	if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowLeft) != keyboardInput.end()) {
		moveX -= 2;
	}
	else if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowRight) != keyboardInput.end()) {
		moveX += 2;
	}
	else {
		moveX += 0.01f * sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	}
	if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowUp) != keyboardInput.end()) {
		moveY -= 2;
	}
	else if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowDown) != keyboardInput.end()) {
		moveY += 2;
	}
	else {
		moveY += 0.01f * sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
	}

	sprite->setPosition(sf::Vector2f(sprite->getPosition().x + moveX, sprite->getPosition().y + moveY));
}

void MainPlayer::update() {}

}