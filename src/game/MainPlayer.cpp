#include <game/MainPlayer.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

namespace game {

MainPlayer::MainPlayer() : SolidObject("MainPlayer", "assets/sprites/stefan-head2.png"), velocity(0.f, 0.f), health(5) {
	sprite = &SolidObject::getSprite();
	sprite->setPosition(sf::Vector2f(400, 360));

	setHitbox(sprite->getGlobalBounds());
}

MainPlayer::~MainPlayer() {}

void MainPlayer::processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) {
	if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowLeft) != keyboardInput.end()) {
		predictedMovement.x -= 8;
		velocity.x = -1.f;
	}
	else if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowRight) != keyboardInput.end()) {
		predictedMovement.x += 8;
		velocity.x = 1.f;
	}
	else {
		float xValue = 0.01f * sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		predictedMovement.x += xValue;
		velocity.x = (xValue > 0.f ? 1.f : xValue < 0.f ? -1.f : 0.f);
	}
	if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowUp) != keyboardInput.end()) {
		predictedMovement.y -= 8;
		velocity.y = -1.f;
	}
	else if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowDown) != keyboardInput.end()) {
		predictedMovement.y += 8;
		velocity.y = 1.f;
	}
	else {
		float yValue = 0.01f * sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
		predictedMovement.y += yValue;
		velocity.y = (yValue > 0.f ? 1.f : yValue < 0.f ? -1.f : 0.f);
	}

	predictedHitbox = sf::FloatRect(getHitbox().left + predictedMovement.x, getHitbox().top + predictedMovement.y, getHitbox().width, getHitbox().height);
}

void MainPlayer::update() {
	sprite->setPosition(sf::Vector2f(sprite->getPosition().x + predictedMovement.x, sprite->getPosition().y + predictedMovement.y));
	predictedMovement = sf::Vector2f(0, 0);
	setHitbox(sprite->getGlobalBounds());
	if (invinsibilityFrames > 0) {
		invinsibilityFrames--;
	}
}

const sf::Vector2f& MainPlayer::getVelocity() {
	return velocity;
}

void MainPlayer::resolveCollisionWithWall(const sf::FloatRect& wallHitbox, FloorType floorType) {
	if (!predictedHitbox.intersects(wallHitbox)) {
		return;
	}
	switch (floorType) {
		case FloorType::normal: {
			if (predictedHitbox.top < wallHitbox.top + wallHitbox.height) {
				predictedMovement.y = 0.f;
				velocity.y = 0.f;
			}
			else if (predictedHitbox.top + predictedHitbox.height > wallHitbox.top) {
				predictedMovement.y = 0.f;
				velocity.y = 0.f;
			}
			break;
		}
		case FloorType::edge: {
			if (predictedHitbox.top + predictedHitbox.height <= wallHitbox.top || predictedHitbox.top >= wallHitbox.top + wallHitbox.height) {
				break;
			} else {
				predictedMovement.y = 0.f;
				velocity.y = 0.f;
			}
			if (predictedHitbox.left < wallHitbox.left + wallHitbox.width) {
				predictedMovement.x = 0.f;
				velocity.x = 0.f;
			}
			else if (predictedHitbox.left + predictedHitbox.width > wallHitbox.left) {
				predictedMovement.x = 0.f;
				velocity.x = 0.f;
			}
			break;
		}
	}
}

int MainPlayer::getHealth() { return health; }

void MainPlayer::setHealth(int value) { 
	if (invinsibilityFrames <= 0) {
		health = value;
		invinsibilityFrames = 60;
	}
}

int MainPlayer::getInvinsibilityFrames() { return invinsibilityFrames; }

}