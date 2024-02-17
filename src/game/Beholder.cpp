#include <game/Beholder.h>

#include <SFML/System.hpp>

namespace game {

Beholder::Beholder(int counter, sf::Vector2f position) : SolidObject("beholder" + std::to_string(counter), "assets/sprites/WIP32x32.png"), raySprite("beholder" + std::to_string(counter) + "RaySprite"), rayTexture("assets/sprites/beholder-ray.png") {
	sprite = &SolidObject::getSprite();
	sprite->setPosition(position);

	setHitbox(sprite->getGlobalBounds());

	raySprite.setTexture(rayTexture);
	raySprite.setPosition(sf::Vector2f(position.x, position.y + 16));
	
}

void Beholder::update() {}

drawable::Sprite& Beholder::getRaySprite() { return raySprite; }

}