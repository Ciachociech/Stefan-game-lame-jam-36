#ifndef DRAWABLE_TEXT_H_
#define DRAWABLE_TEXT_H_

#include <string>

#include <SFML/Graphics.hpp>

namespace drawable {

class Text : public sf::Text {
private:
	const std::string tag;
public:
	Text(const std::string tag);

	void setFont(const sf::Font& font);
	void setTextContent(const std::string text);
	void setCharacterSize(const unsigned int size);
	void setFillColor(const sf::Color color);
	void setPosition(const sf::Vector2f position);

	const std::string& getTag();
};

}

#endif