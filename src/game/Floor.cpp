#include <game/Floor.h>

namespace game {
	
Floor::Floor(int counter) : SolidObject("floor" + std::to_string(counter), "assets/sprites/WIP32x32.png") {
	hitbox = SolidObject::getSprite().getGlobalBounds();
}

void Floor::update() {}


}