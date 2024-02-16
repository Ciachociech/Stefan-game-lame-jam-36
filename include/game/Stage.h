#ifndef GAME_STAGE_H_
#define GAME_STAGE_H_

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include <game/Scene.h>

#include <drawable/Sprite.h>
#include <drawable/Texture.h>
#include <game/Object.h>
#include <game/MainPlayer.h>
#include <window/JoystickInput.h>
#include <window/KeyboardInput.h>

namespace game {

namespace {
	using ObjectUptr = std::unique_ptr<Object>;
}

class Stage : public Scene {

private:
	std::vector<ObjectUptr> objects;
	MainPlayer mainPlayer;
public:
	Stage(sf::RenderWindow* window);

	void processInput(const std::vector<window::PressedKey>& keyboardInput, const std::vector<window::PressedButton>& joystickInput) override;
	bool update() override;
	void render() override;
};

}

#endif // !GAME_STAGE_H_
