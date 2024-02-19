#ifndef GAME_STAGE_H_
#define GAME_STAGE_H_

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include <game/Scene.h>

#include <drawable/Sprite.h>
#include <drawable/Text.h>
#include <drawable/Texture.h>
#include <game/Beholder.h>
#include <game/Finish.h>
#include <game/Floor.h>
#include <game/MainPlayer.h>
#include <game/Object.h>
#include <window/JoystickInput.h>
#include <window/KeyboardInput.h>

namespace game {

namespace {
	using FloorUptr = std::unique_ptr<Floor>;
	using BeholderUptr = std::unique_ptr<Beholder>;
}

class Stage : public Scene {

private:
	std::vector<FloorUptr> floors;
	std::vector<BeholderUptr> beholders;
	Object grid;
	Object health;
	MainPlayer mainPlayer;
	Finish finishTile;

	drawable::Text textLevel;
	drawable::Text textHealth;

	sf::Font font;

	void checkCollision();
	void interpretStagePattern(const std::string* pattern);
	bool isStageCompleted = false;
public:
	Stage(sf::RenderWindow* window, const int stageCounter);

	void processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) override;
	int update() override;
	void render() override;
};

}

#endif // !GAME_STAGE_H_
