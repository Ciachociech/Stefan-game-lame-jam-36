#include <game/Stage.h>

namespace game {

Stage::Stage(sf::RenderWindow* window) : window_(window) { //: Scene(window) {
	drawable::Texture texture = drawable::Texture("assets/sprites/stefan-head2.png");
	drawable::Sprite sprite = drawable::Sprite("example");
	sprite.setTexture(texture);
	sprites.push_back(sprite);
}

void Stage::processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) {
	//TODO
}

bool Stage::update() {
	return true;
}

void Stage::render() {
	//sf::RenderWindow* window = getWindow();
	sf::RenderWindow* window = window_;

	for (int x = 0; x < window->getSize().x / sprites.at(0).getLocalBounds().getSize().x; ++x) {
		for (int y = 0; y < window->getSize().y / sprites.at(0).getLocalBounds().getSize().y; ++y) {
			window->draw(sprites.at(0));
		}
	}
}


}