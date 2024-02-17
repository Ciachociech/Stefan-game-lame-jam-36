#include <game/MainPlayer.h>

namespace game {

MainPlayer::MainPlayer() : SolidObject("MainPlayer", "assets/sprites/stefan-head2.png"), velocity(0.f, 0.f) {
	sprite = &SolidObject::getSprite();
	sprite->setPosition(sf::Vector2f(400, 360));
	sprite->setOriginCenter();

	setHitbox(sprite->getGlobalBounds());
}

MainPlayer::~MainPlayer() {}

void MainPlayer::processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) {
	float moveX = 0;
	float moveY = 0;
	if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowLeft) != keyboardInput.end()) {
		moveX -= 2;
		velocity.x = -1.f;
	}
	else if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowRight) != keyboardInput.end()) {
		moveX += 2;
		velocity.x = 1.f;
	}
	else {
		float xValue = 0.01f * sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		moveX += xValue;
		velocity.x = (xValue > 0.f ? 1.f : xValue < 0.f ? -1.f : 0.f);
	}
	if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowUp) != keyboardInput.end()) {
		moveY -= 2;
		velocity.y = -1.f;
	}
	else if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowDown) != keyboardInput.end()) {
		moveY += 2;
		velocity.y = 1.f;
	}
	else {
		float yValue = 0.01f * sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
		moveY += yValue;
		velocity.y = (yValue > 0.f ? 1.f : yValue < 0.f ? -1.f : 0.f);
	}

	sprite->setPosition(sf::Vector2f(sprite->getPosition().x + moveX, sprite->getPosition().y + moveY));
	setHitbox(sprite->getGlobalBounds());
}

void MainPlayer::update() {
}

const sf::Vector2f& MainPlayer::getVelocity() {
	return velocity;
}

void MainPlayer::resolveCollisionWithWall(const sf::FloatRect& wallHitbox) {
	if (getHitbox().left + getHitbox().width / 2 > wallHitbox.left + wallHitbox.width) {
		sprite->setPosition(sf::Vector2f(wallHitbox.left + wallHitbox.width + getHitbox().width / 2 + 1.f, sprite->getPosition().y));
		velocity.x = 0.f;
	}
	else if (getHitbox().left + getHitbox().width - getHitbox().width / 2 < wallHitbox.left) {
		sprite->setPosition(sf::Vector2f(wallHitbox.left - getHitbox().width / 2 - 1.f, sprite->getPosition().y));
		velocity.x = 0.f;
	}
	if (getHitbox().top + getHitbox().height / 2 > wallHitbox.top + wallHitbox.height) {
		sprite->setPosition(sf::Vector2f(sprite->getPosition().x, wallHitbox.top + getHitbox().width / 2 + wallHitbox.height + 1.f));
		velocity.x = 0.f;
	}
	else if (getHitbox().top + getHitbox().height - getHitbox().height / 2 < wallHitbox.top) {
		sprite->setPosition(sf::Vector2f(sprite->getPosition().x, wallHitbox.top - getHitbox().width / 2 - 1.f));
		velocity.x = 0.f;
	}

	setHitbox(sprite->getGlobalBounds());
}

}