#include <game/Beholder.h>

#include <SFML/System.hpp>

namespace game {

Beholder::Beholder(int counter, sf::Vector2f position) : SolidObject("beholder" + std::to_string(counter), "assets/sprites/concept-asset.png"), raySprite("beholder" + std::to_string(counter) + "RaySprite"), rayTexture("assets/sprites/beholder-ray.png") {
	sprite = &SolidObject::getSprite();
	sprite->setTextureRect(sf::IntRect(192, 32, 32, 32));
	sprite->setPosition(position);

	setHitbox(sprite->getGlobalBounds());

	raySprite.setTexture(rayTexture);
	raySprite.setPosition(sf::Vector2f(position.x, position.y + 10));
	
	rayHitboxes.push_back(sf::FloatRect(raySprite.getPosition().x + 8, raySprite.getPosition().y, 14, 41));
	rayHitboxes.push_back(sf::FloatRect(raySprite.getPosition().x + 8, raySprite.getPosition().y + 41, 20, 47));
	rayHitboxes.push_back(sf::FloatRect(raySprite.getPosition().x + 8, raySprite.getPosition().y + 88, 26, 40));
}

void Beholder::update() {
	if (rayCounter-- == 0) {
		isRayActive = true;
	}
	else if (rayCounter <= -120) {
		rayCounter = 120;
		isRayActive = false;
	}
}

drawable::Sprite& Beholder::getRaySprite() { return raySprite; }

const std::vector<sf::FloatRect>& Beholder::getRayHitboxes() { return rayHitboxes; }

bool Beholder::getIsRayActive() { return isRayActive; }

}