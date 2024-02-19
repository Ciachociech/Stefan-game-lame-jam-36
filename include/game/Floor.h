#ifndef GAME_FLOOR_H_
#define GAME_FLOOR_H_

#include <game/SolidObject.h>

namespace game {

enum class FloorType { stone, grass, brick, none };

class Floor : public SolidObject {
private:
	bool isHitboxSet = false;
	FloorType floorType_;
public:
	Floor(int counter, FloorType floorType);

	void update() override;
	
	FloorType& getFloorType();
};

}

#endif // !GAME_FLOOR_H_
