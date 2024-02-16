#include <drawable/Text.h>

namespace drawable {

Text::Text(const std::string tag) : sf::Text(), tag(tag) {}

void Text::setFont(const sf::Font& font) {
	sf::Text::setFont(font);
}

void Text::setTextContent(const std::string text) {
	sf::Text::setString(text);
}

void Text::setCharacterSize(const unsigned int size) {
	sf::Text::setCharacterSize(size);
}

void Text::setFillColor(const sf::Color color) {
	sf::Text::setFillColor(color);
}

void Text::setPosition(const sf::Vector2f position) {
	sf::Text::setPosition(position);
}

const std::string& Text::getTag() {
	return this->tag;
}

}