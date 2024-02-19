#ifndef GAME_TITLESCREEN_H_
#define GAME_TITLESCREEN_H_

#include <SFML/Graphics.hpp>

#include <drawable/Text.h>
#include <game/Object.h>
#include <game/Scene.h>

namespace game {

class Titlescreen : public Scene {
private:
	Object titlescreen;
	drawable::Text startText;

	sf::Font font;

	bool isAnyInput = false;
	int blinkCounter = 10;
public:
	Titlescreen(sf::RenderWindow* window);

	void processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) override;
	int update() override;
	void render() override;
};

}

#endif // !GAME_TITLESCREEN_H_
