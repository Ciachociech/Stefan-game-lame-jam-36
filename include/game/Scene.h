#ifndef GAME_SCENE_H_
#define GAME_SCENE_H_

#include <SFML/Graphics.hpp>

namespace game {

class Scene {
private:
	sf::RenderWindow* window;
public:
	Scene(sf::RenderWindow* window);
};

}

#endif // !GAME_SCENE_H_
