#include <game/Titlescreen.h>

namespace game {

Titlescreen::Titlescreen(sf::RenderWindow* window) : Scene(window), titlescreen("titlescreen", "assets/sprites/titlescreen.png"), startText("startText") {
	titlescreen.getSprite().setPosition(sf::Vector2f(0, 0));

	font.loadFromFile("assets/fonts/NerkoOne-Regular.ttf");

	startText.setTextContent("<press any button to start>");
	startText.setFont(font);
	startText.setPosition(sf::Vector2f(221, 420));
	startText.setFillColor(sf::Color(92, 69, 57, 255));
	startText.setCharacterSize(32);
}

void Titlescreen::processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) {
	if (keyboardInput.size() != 0 || joystickInput.size() != 0) { isAnyInput = true; }
}

int Titlescreen::update() {
	if (isAnyInput) { return 1; }
	if (blinkCounter-- < -30) {
		blinkCounter = 30;
	}
	return 0;
}

void Titlescreen::render() {
	getWindow()->draw(titlescreen.getSprite());
	if (blinkCounter >= 0) { getWindow()->draw(startText); }
	
}

}