#ifndef GAME_GAMEOVER_H_
#define GAME_GAMEOVER_H_

#include <SFML/Graphics.hpp>

#include <game/Scene.h>

#include <drawable/Text.h>

namespace game {

class Gameover : public Scene {
private:
	sf::RectangleShape bigWindow;
	sf::RectangleShape frameOuter;
	sf::RectangleShape frameInner;
	drawable::Text textUpper;
	drawable::Text textLower;

	sf::Font font;

	int waitForInput = 30;
	bool isAnyInput = false;
public:
	Gameover(sf::RenderWindow* window);

	void processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) override;
	bool update() override;
	void render() override;
};

}

#endif // !GAME_GAMEOVER_H_
