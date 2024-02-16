#include <game/Stage.h>

namespace game {

Stage::Stage(sf::RenderWindow* window) : Scene(window), objects(), mainPlayer() {
	objects.push_back(std::make_unique<game::Object>("grid", "assets/sprites/grid-part.png"));
}

void Stage::processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) {
	mainPlayer.processInput(keyboardInput, joystickInput);
}

bool Stage::update() {
	mainPlayer.update();
	return true;
}

void Stage::render() {
	sf::RenderWindow* window = getWindow();

	int gridX = objects.at(0)->getSprite().getLocalBounds().getSize().x;
	int gridY = objects.at(0)->getSprite().getLocalBounds().getSize().y;
	for (int x = 0; x < window->getSize().x / gridX; ++x) {
		for (int y = 0; y < window->getSize().y / gridY; ++y) {
			objects.at(0)->getSprite().setPosition(sf::Vector2f(x * gridX, y * gridY));
			window->draw(objects.at(0)->getSprite());
		}
	}

	window->draw(mainPlayer.getSprite());
}


}