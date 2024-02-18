#include <game/MainPlayer.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

namespace game {

namespace {
	const float g{ -9.81 / 2 };
	bool jump_flag{ false };
}

MainPlayer::MainPlayer() : SolidObject("MainPlayer", "assets/sprites/stefan-head2.png"), velocity(0.f, 0.f), health(5) {
	sprite = &SolidObject::getSprite();
	sprite->setPosition(sf::Vector2f(400, 360));

	setHitbox(sprite->getGlobalBounds());
}

MainPlayer::~MainPlayer() {}

void MainPlayer::processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) {
	if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowLeft) != keyboardInput.end()) {
		velocity.x = -8.f;
	}
	else if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowRight) != keyboardInput.end()) {
		velocity.x = 8.f;
	}
	else if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) != 0.0) {
		velocity.x *= 0.01f * sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	}

	if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::space) != keyboardInput.end() || std::find(joystickInput.begin(), joystickInput.end(), window::PressedButton::A) != joystickInput.end()) {
		if (jump_flag == false)	jump_flag = jump(sf::Vector2f(sprite->getPosition().x, sprite->getPosition().y));
	}
	if (velocity.y == 0.f)	jump_flag = false;

	if (!collision) {
		velocity.y = 1.f;
		predictedMovement.y += velocity.y;
	}

	predictedMovement.x = velocity.x;
	predictedHitbox = sf::FloatRect(getHitbox().left + predictedMovement.x, getHitbox().top + predictedMovement.y, getHitbox().width, getHitbox().height);
}

bool MainPlayer::jump(const sf::Vector2f position) {
	//auto x0y0 = sf::Vector2f(position.x, position.y);
	velocity.y = -45.f;
	predictedMovement.y += velocity.y - g / 2;
	return true;
}

void MainPlayer::update() {
	sprite->setPosition(sf::Vector2f(sprite->getPosition().x + predictedMovement.x, sprite->getPosition().y + predictedMovement.y));
	predictedMovement = sf::Vector2f(0, 0);
	setHitbox(sprite->getGlobalBounds());
	if (invinsibilityFrames > 0) {
		invinsibilityFrames--;
	}
	velocity.x *= 0.8;
}

const sf::Vector2f& MainPlayer::getVelocity() {
	return velocity;
}

void MainPlayer::resolveCollisionWithWall(const sf::FloatRect& wallHitbox, FloorType floorType) {
	if (!predictedHitbox.intersects(wallHitbox)) {
		collision = false;
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