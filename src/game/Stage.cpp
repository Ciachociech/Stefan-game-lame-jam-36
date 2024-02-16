#include <game/Stage.h>

namespace game {

Stage::Stage(sf::RenderWindow* window) : Scene(window), texture(drawable::Texture("assets/sprites/grid-part.png")), mainPlayer() {
	drawable::Sprite sprite = drawable::Sprite("example");
	sprite.setTexture(texture);
	sprites.push_back(sprite);
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

	for (int x = 0; x < window->getSize().x / sprites.at(0).getLocalBounds().getSize().x; ++x) {
		for (int y = 0; y < window->getSize().y / sprites.at(0).getLocalBounds().getSize().y; ++y) {
			sprites.at(0).setPosition(sf::Vector2f(x * sprites.at(0).getLocalBounds().getSize().x, y * sprites.at(0).getLocalBounds().getSize().y));
			window->draw(sprites.at(0));
		}
	}

	window->draw(mainPlayer.getSprite());
}


}