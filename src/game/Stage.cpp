#include <game/Stage.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <game/StagePatterns.h>

namespace game {
	
void Stage::checkCollision() {
	if (mainPlayer.getHitbox().left < 0) {
		mainPlayer.getSprite().setPosition(sf::Vector2f(0, mainPlayer.getSprite().getPosition().y));
	} else if (mainPlayer.getHitbox().left + mainPlayer.getHitbox().width > 800) {
		mainPlayer.getSprite().setPosition(sf::Vector2f(800 - mainPlayer.getHitbox().width, mainPlayer.getSprite().getPosition().y));
	}
	
	for (const auto& floor : floors) {
		mainPlayer.resolveCollisionWithWall(floor->getHitbox(), floor->getFloorType());
	}

	for (const auto& beholder : beholders) {
		if (mainPlayer.getHitbox().intersects(beholder->getHitbox())) {
			//printf("Interaction with beholder!");
		}
		if (!beholder->getIsRayActive()) { continue; }
		for (const auto& beholderRay : beholder->getRayHitboxes()) {
			if (mainPlayer.getHitbox().intersects(beholderRay)) {
				//printf("Interaction with beholder's ray!");
			}
		}
	}

	for (const auto& beholder : beholders) {
		if (mainPlayer.getHitbox().intersects(beholder->getHitbox())) {
			//printf("Interaction with beholder!");
		}
		if (!beholder->getIsRayActive()) { continue; }
		for (const auto& beholderRay : beholder->getRayHitboxes()) {
			if (mainPlayer.getHitbox().intersects(beholderRay)) {
				//printf("Interaction with beholder's ray!");
				mainPlayer.setHealth(mainPlayer.getHealth() - 1);
				mainPlayer.getSprite().setPosition(sf::Vector2f(700, 384));
			}
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
					floors.push_back(std::make_unique<Floor>(++floorCounter, FloorType::normal));
					floors.at(floorCounter - 1)->getSprite().setPosition(sf::Vector2f(static_cast<float>(x * gridX), static_cast<float>((y + 1) * gridY)));
					floors.at(floorCounter - 1)->update();
					break;
				}
				case 'E': {
					floors.push_back(std::make_unique<Floor>(++floorCounter, FloorType::edge));
					floors.at(floorCounter - 1)->getSprite().setPosition(sf::Vector2f(static_cast<float>(x * gridX), static_cast<float>((y + 1) * gridY)));
					floors.at(floorCounter - 1)->update();
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
	beholders.push_back(std::make_unique<Beholder>(0, sf::Vector2f(384.f, 168.f)));
	beholders.push_back(std::make_unique<Beholder>(0, sf::Vector2f(544.f, 350.f)));
	beholders.push_back(std::make_unique<Beholder>(0, sf::Vector2f(512.f, 318.f)));
	beholders.push_back(std::make_unique<Beholder>(0, sf::Vector2f(480.f, 286.f)));
}

void Stage::processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) {
	mainPlayer.processInput(keyboardInput, joystickInput);
}

bool Stage::update() {
	checkCollision();
	mainPlayer.update();

	for (const auto& beholder : beholders) {
		beholder->update();
	}

	if (mainPlayer.getHealth() <= 0) { return false; }
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