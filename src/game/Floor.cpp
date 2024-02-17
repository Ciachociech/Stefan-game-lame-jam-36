#include <game/Floor.h>

namespace game {
	
Floor::Floor(int counter) : SolidObject("floor" + std::to_string(counter), "assets/sprites/stone-test.png") {}

void Floor::update() {
	if (!isHitboxSet) {
		setHitbox(getSprite().getGlobalBounds());
	}
}

}