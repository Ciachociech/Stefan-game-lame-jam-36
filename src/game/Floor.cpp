#include <game/Floor.h>

namespace game {
	
Floor::Floor(int counter, FloorType floorType) : SolidObject("floor" + std::to_string(counter), "assets/sprites/stone-test.png"), floorType_(floorType) {}

void Floor::update() {
	if (!isHitboxSet) {
		setHitbox(getSprite().getGlobalBounds());
	}
}

FloorType& Floor::getFloorType() {
	return floorType_;
}

}