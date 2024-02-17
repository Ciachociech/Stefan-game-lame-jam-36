#include <game/Stage.h>

#include <game/StagePatterns.h>

namespace game {
	
void Stage::checkCollision() {
	if (mainPlayer.getHitbox().left < 0) {
		mainPlayer.getSprite().setPosition(sf::Vector2f(mainPlayer.getSprite().getLocalBounds().getSize().x / 2, mainPlayer.getSprite().getPosition().y));
	} else if (mainPlayer.getHitbox().left + mainPlayer.getHitbox().width > getWindow()->getSize().x) {
		mainPlayer.getSprite().setPosition(sf::Vector2f(getWindow()->getSize().x - mainPlayer.getSprite().getLocalBounds().getSize().x / 2, mainPlayer.getSprite().getPosition().y));
	}
	
	for (const auto& floor : floors) {
		if (mainPlayer.getHitbox().intersects(floor->getHitbox())) {
			mainPlayer.resolveCollisionWithWall(floor->getHitbox());
		}
	}
}

void Stage::interpretStagePattern(const std::string* pattern) {
	int floorCounter = 0;
	const int gridX = grid.getSprite().getLocalBounds().getSize().x;
	const int gridY = grid.getSprite().getLocalBounds().getSize().y;

	for (int x = 0; x < 25; ++x) {
		for (int y = 0; y < 13; ++y) {
			switch (pattern[y].at(x)) {
				case 'X': {
					floors.push_back(std::make_unique<Floor>(++floorCounter));
					floors.at(floorCounter - 1)->getSprite().setPosition(sf::Vector2f(static_cast<float>(x * gridX), static_cast<float>((y + 1) * gridY)));
					break;
				}
				default: {
					break;
				}
			}
		}
	}
}

Stage::Stage(sf::RenderWindow* window) : Scene(window), floors(), grid("grid", "assets/sprites/grid-part.png"), mainPlayer() {
	interpretStagePattern(pattern1);
}

void Stage::processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) {
	mainPlayer.processInput(keyboardInput, joystickInput);
}

bool Stage::update() {
	checkCollision();
	mainPlayer.update();
	for (const auto& floor : floors) {
		floor->update();
	}
	return true;
}

void Stage::render() {
	sf::RenderWindow* window = getWindow();

	const int gridX = grid.getSprite().getLocalBounds().getSize().x;
	const int gridY = grid.getSprite().getLocalBounds().getSize().y;
	for (int x = 0; x < window->getSize().x / gridX; ++x) {
		for (int y = 1; y < window->getSize().y / gridY - 1; ++y) {
			grid.getSprite().setPosition(sf::Vector2f(static_cast<float>(x * gridX), static_cast<float>(y * gridY)));
			window->draw(grid.getSprite());
		}
	}

	for (const auto& floor : floors) {
		window->draw(floor->getSprite());
	}

	window->draw(mainPlayer.getSprite());
}


}