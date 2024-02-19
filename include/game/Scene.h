#ifndef GAME_SCENE_H_
#define GAME_SCENE_H_

#include <vector>

#include <SFML/Graphics.hpp>

#include <window/JoystickInput.h>
#include <window/KeyboardInput.h>

namespace game {

class Scene {
private:
	sf::RenderWindow* window_;
protected:
	sf::RenderWindow* getWindow() { return window_; }
public:
	Scene(sf::RenderWindow* window) : window_(window) {}

	virtual void processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) = 0;
	virtual int update() = 0;
	virtual void render() = 0;
};

}

#endif // !GAME_SCENE_H_
