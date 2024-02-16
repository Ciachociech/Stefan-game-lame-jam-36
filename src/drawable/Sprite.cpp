#include <drawable/Sprite.h>

namespace drawable {

Sprite::Sprite(const std::string tag) : sf::Sprite(), tag(tag) {}

void Sprite::setTexture(const Texture& texture) {
	sf::Sprite::setTexture(texture);
}

void Sprite::setTexture(const Texture& texture, const sf::IntRect textureRect) {
	sf::Sprite::setTexture(texture);
	sf::Sprite::setTextureRect(textureRect);
}

void Sprite::setTextureRect(const sf::IntRect textureRect) {
	if (sf::Sprite::getTexture() != NULL) {
		sf::Sprite::setTextureRect(textureRect);
	}
}

void Sprite::setColor(const sf::Color color) {
	sf::Sprite::setColor(color);
}

void Sprite::setPosition(const sf::Vector2f position) {
	sf::Sprite::setPosition(position);
}

void Sprite::move(const sf::Vector2f offset) {
	sf::Sprite::move(offset);
}

void Sprite::setRotation(const float rotation) {
	sf::Sprite::setRotation(rotation);
}

void Sprite::rotate(const float offset) {
	sf::Sprite::rotate(offset);
}

void Sprite::setScale(const sf::Vector2f scale) {
	sf::Sprite::setScale(scale);
}

void Sprite::scale(const sf::Vector2f factor) {
	sf::Sprite::scale(factor);
}

void Sprite::setOriginCenter() {
	const auto bounds = sf::Sprite::getLocalBounds().getSize();
	sf::Sprite::setOrigin(sf::Vector2f(bounds.x / 2, bounds.y / 2));
}

const std::string& Sprite::getTag() {
	return this->tag;
}

}