#include <game/MainPlayer.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

namespace game {

namespace {
	const float g = -9.81;
}

MainPlayer::MainPlayer() : SolidObject("MainPlayer", "assets/sprites/stefan-head2.png"), velocity(0.f, 0.f) {
	sprite = &SolidObject::getSprite();
	sprite->setPosition(sf::Vector2f(400, 360));

	setHitbox(sprite->getGlobalBounds());
}

MainPlayer::~MainPlayer() {}

void MainPlayer::processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) {
	if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowLeft) != keyboardInput.end()) {
		predictedMovement.x -= 2;
		velocity.x = -1.f;
	}
	else if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowRight) != keyboardInput.end()) {
		predictedMovement.x += 2;
		velocity.x = 1.f;
	}
	else {
		float xValue = 0.01f * sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		predictedMovement.x += xValue;
		velocity.x = (xValue > 0.f ? 1.f : xValue < 0.f ? -1.f : 0.f);
	}

	//
	// No need for the lines below as we don't move upward!
	// 
	//if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowUp) != keyboardInput.end()) {
	//	predictedMovement.y -= 2;
	//	velocity.y = -1.f;
	//}
	//else if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::arrowDown) != keyboardInput.end()) {
	//	predictedMovement.y += 2;
	//	velocity.y = 1.f;
	//}
	//else {
	//	float yValue = 0.01f * sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
	//	predictedMovement.y += yValue;
	//	velocity.y = (yValue > 0.f ? 1.f : yValue < 0.f ? -1.f : 0.f);
	//}

	if (std::find(keyboardInput.begin(), keyboardInput.end(), window::PressedKey::space) != keyboardInput.end()) {
		jump(sf::Vector2f(sprite->getPosition().x, sprite->getPosition().y), 1);
	}

	if (!collision) {
		velocity.y = 1.f;
		predictedMovement.y += velocity.y;// * time - g * time * time / 2;
	}

	predictedHitbox = sf::FloatRect(getHitbox().left + predictedMovement.x, getHitbox().top + predictedMovement.y, getHitbox().width, getHitbox().height);
}

void MainPlayer::jump(const sf::Vector2f position, int time) {
	//auto x0y0 = sf::Vector2f(position.x, position.y);
	velocity.y = -15.f;
	predictedMovement.y += velocity.y * time - g * time * time / 2;

	// notatki stare
	// rzut pionowy: y = y0 + vy*t + g*t*t/2
	//sprite->setPosition(sf::Vector2f(position.x, position.y + velocity.y * time - g * time * time / 2));
	// rzut ukosny: x = x0 + vx*t, y = y0 + vy*t + g*t*t/2
	//sprite->setPosition(sf::Vector2f(position.x + velocity.x * time, position.y + velocity.y * time - g * time * time / 2));
	//while (!collision) {
	//	jump(x0y0, time + 1);
	//}
}

void MainPlayer::update() {
	sprite->setPosition(sf::Vector2f(sprite->getPosition().x + predictedMovement.x, sprite->getPosition().y + predictedMovement.y));
	predictedMovement = sf::Vector2f(0, 0);
	setHitbox(sprite->getGlobalBounds());
}

const sf::Vector2f& MainPlayer::getVelocity() {
	return velocity;
}

void MainPlayer::resolveCollisionWithWall(const sf::FloatRect& wallHitbox) {
	if (!predictedHitbox.intersects(wallHitbox)) {
		collision = false;
		return;
	}
	if (predictedHitbox.top < wallHitbox.top + wallHitbox.height) {
		collision = true;
		predictedMovement.y = 0.f;
		velocity.y = 0.f;
	}
	else if (predictedHitbox.top + predictedHitbox.height > wallHitbox.top) {
		collision = true;
		predictedMovement.y = 0.f;
		velocity.y = 0.f;
	}
	/*
	if (predictedHitbox.left < wallHitbox.left + wallHitbox.width) {
		predictedMovement.x = 0.f;
		velocity.x = 0.f;
	}
	else if (predictedHitbox.left + predictedHitbox.width > wallHitbox.left) {
		predictedMovement.x = 0.f;
		velocity.x = 0.f;
	}
	*/
}

}