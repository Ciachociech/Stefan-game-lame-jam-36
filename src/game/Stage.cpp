#include <game/Stage.h>

#include <game/StagePatterns.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

namespace game {
	
void Stage::checkCollision() {
	for (const auto& floor : floors) {
		mainPlayer.resolveCollisionWithWall(floor->getHitbox(), floor->getFloorType());
	}

	for (const auto& beholder : beholders) {
		if (mainPlayer.getHitbox().intersects(beholder->getHitbox())) {
			mainPlayer.setHealth(mainPlayer.getHealth() - 1);
			mainPlayer.getSprite().setPosition(sf::Vector2f(700, 384));
		}
		if (!beholder->getIsRayActive()) { continue; }
		for (const auto& beholderRay : beholder->getRayHitboxes()) {
			if (mainPlayer.getHitbox().intersects(beholderRay)) {
				mainPlayer.setHealth(mainPlayer.getHealth() - 1);
				mainPlayer.getSprite().setPosition(sf::Vector2f(700, 384));
			}
		}
	}
}

void Stage::interpretStagePattern(const std::string* pattern) {
	int floorCounter = 0;
	int beholderCounter = 0;
	const int gridX = grid.getSprite().getLocalBounds().getSize().x;
	const int gridY = grid.getSprite().getLocalBounds().getSize().y;

	for (int x = 0; x < 25; ++x) {
		for (int y = 0; y < 13; ++y) {
			switch (pattern[y].at(x)) {
				case 'S': {
					floors.push_back(std::make_unique<Floor>(++floorCounter, FloorType::stone));
					floors.at(floorCounter - 1)->getSprite().setPosition(sf::Vector2f(static_cast<float>(x * gridX), static_cast<float>((y + 1) * gridY)));
					floors.at(floorCounter - 1)->update();
					break;
				}
				case 'G': {
					floors.push_back(std::make_unique<Floor>(++floorCounter, FloorType::grass));
					floors.at(floorCounter - 1)->getSprite().setPosition(sf::Vector2f(static_cast<float>(x * gridX), static_cast<float>((y + 1) * gridY)));
					floors.at(floorCounter - 1)->update();
					break;
				}
				case 'R': {
					floors.push_back(std::make_unique<Floor>(++floorCounter, FloorType::brick));
					floors.at(floorCounter - 1)->getSprite().setPosition(sf::Vector2f(static_cast<float>(x * gridX), static_cast<float>((y + 1) * gridY)));
					floors.at(floorCounter - 1)->update();
					break;
				}
				case 'B': {
					floors.push_back(std::make_unique<Floor>(++floorCounter, FloorType::stone));
					floors.at(floorCounter - 1)->getSprite().setPosition(sf::Vector2f(static_cast<float>(x * gridX), static_cast<float>((y + 1) * gridY)));
					floors.at(floorCounter - 1)->update();
					beholders.push_back(std::make_unique<Beholder>(++beholderCounter, sf::Vector2f(static_cast<float>(x * gridX), static_cast<float>((y + 1) * gridY))));
					break;
				}
				default: {
					break;
				}
			}
		}
	}
}

Stage::Stage(sf::RenderWindow* window, const int stageCounter) : Scene(window), floors(), grid("grid", "assets/sprites/grid-part.png"), health("health", "assets/sprites/concept-asset.png"), mainPlayer(), textHealth("textHealth"), textLevel("textLevel") {
	switch (stageCounter) {
		case 1: defualt: {
			interpretStagePattern(pattern1);
			break;
		}
		case 2: {
			interpretStagePattern(pattern2);
			break;
		}
		case 3: {
			interpretStagePattern(pattern3);
			break;
		}
	}

	sf::Color lighterStefanColor = sf::Color(180, 161, 151, 255);
	font.loadFromFile("assets/fonts/NerkoOne-Regular.ttf");

	textHealth.setTextContent(" level: " + std::to_string(stageCounter) + "/3");
	textHealth.setFont(font);
	textHealth.setPosition(sf::Vector2f(0, -8));
	textHealth.setFillColor(lighterStefanColor);
	textHealth.setCharacterSize(32);

	textLevel.setTextContent("health:");
	textLevel.setFont(font);
	textLevel.setPosition(sf::Vector2f(8, 448));
	textLevel.setFillColor(lighterStefanColor);
	textLevel.setCharacterSize(32);
	
	health.getSprite().setTextureRect(sf::IntRect(128, 32, 32, 32));
}

void Stage::processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) {
	mainPlayer.processInput(keyboardInput, joystickInput);
}

int Stage::update() {
	checkCollision();
	mainPlayer.update();

	for (const auto& beholder : beholders) {
		beholder->update();
	}

	if (mainPlayer.getHealth() <= 0) { return -1; }
	if (isStageCompleted) { return 1; }
	return 0;
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

	window->draw(textHealth);
	window->draw(textLevel);

	for (int i = 0; i < mainPlayer.getHealth(); ++i) {
		health.getSprite().setPosition(sf::Vector2f(96 + i * (gridX + 8), 448));
		window->draw(health.getSprite());
	}

	for (const auto& floor : floors) {
		window->draw(floor->getSprite());
	}

	for (const auto& beholder : beholders) {
		window->draw(beholder->getSprite());
		if (beholder->getIsRayActive()) {
			window->draw(beholder->getRaySprite(), sf::RenderStates(sf::BlendAdd));
		}
	}

	if (mainPlayer.getInvinsibilityFrames() % 10 < 5) {
		window->draw(mainPlayer.getSprite());
	}
}


}