#include <game/Gameover.h>

namespace game {

Gameover::Gameover(sf::RenderWindow* window) : Scene(window), bigWindow(sf::Vector2f(400, 200)), frameOuter(sf::Vector2f(360, 180)), frameInner(sf::Vector2f(320, 160)), textUpper("gameoverText1"), textLower("gameoverText2") {
	bigWindow.setFillColor(sf::Color(180, 161, 151, 255));
	bigWindow.setPosition(sf::Vector2f(200, 140));

	sf::Color darkerStefanColor = sf::Color(92, 69, 57, 255);

	frameOuter.setOutlineColor(darkerStefanColor);
	frameOuter.setOutlineThickness(4.f);
	frameOuter.setPosition(sf::Vector2f(220, 150));

	frameInner.setOutlineColor(darkerStefanColor);
	frameInner.setOutlineThickness(4.f);
	frameInner.setPosition(sf::Vector2f(240, 160));

	font.loadFromFile("assets/fonts/NerkoOne-Regular.ttf");

	textUpper.setTextContent("game over");
	textUpper.setFont(font);
	textUpper.setPosition(sf::Vector2f(250, 150));
	textUpper.setFillColor(darkerStefanColor);
	textUpper.setCharacterSize(56);

	textLower.setTextContent("press any button\nto play again");
	textLower.setFont(font);
	textLower.setPosition(sf::Vector2f(250, 220));
	textLower.setFillColor(darkerStefanColor);
	textLower.setCharacterSize(36);
}

void Gameover::processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) {
	if (keyboardInput.size() != 0 || joystickInput.size() != 0) { isAnyInput = true; }
}

bool Gameover::update() {
	if (isAnyInput && waitForInput-- < 0) { 
		waitForInput = 30;
		return false; 
	}
	return true;
}

void Gameover::render() {
	getWindow()->draw(bigWindow);
	getWindow()->draw(frameOuter);
	getWindow()->draw(frameInner);
	getWindow()->draw(textUpper);
	getWindow()->draw(textLower);
}

}