#ifndef DRAWABLE_SPRITE_H_
#define DRAWABLE_SPRITE_H_

#include <string>

#include <SFML/Graphics.hpp>

#include <drawable/Texture.h>

namespace drawable {

class Sprite : public sf::Sprite {
private:
	const std::string tag;
public:
	Sprite(const std::string tag);

	void setTexture(const Texture& texture);
	void setTexture(const Texture& texture, const sf::IntRect textureRect);
	void setTextureRect(const sf::IntRect textureRect);
	void setColor(const sf::Color color);
	void setPosition(const sf::Vector2f position);
	void move(const sf::Vector2f offset);
	void setRotation(const float rotation);
	void rotate(const float offset);
	void setScale(const sf::Vector2f scale);
	void scale(const sf::Vector2f factor);
	void setOriginCenter();

	const std::string& getTag();
};

}

#endif