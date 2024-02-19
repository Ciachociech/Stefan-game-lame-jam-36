#include <game/Floor.h>

namespace game {
	
Floor::Floor(int counter, FloorType floorType) : SolidObject("floor" + std::to_string(counter), "assets/sprites/concept-asset.png"), floorType_(floorType) {
	switch (floorType_) {
		case FloorType::stone: {
			getSprite().setTextureRect(sf::IntRect(0, 64, 32, 32));
			break;
		}
		case FloorType::grass: {
			getSprite().setTextureRect(sf::IntRect(0, 0, 32, 32));
			break;
		}
		case FloorType::brick: {
			getSprite().setTextureRect(sf::IntRect(0, 32, 32, 32));
			break;
		}
	}
}

void Floor::update() {
	if (!isHitboxSet) {
		setHitbox(getSprite().getGlobalBounds());
	}
}

FloorType& Floor::getFloorType() {
	return floorType_;
}

}