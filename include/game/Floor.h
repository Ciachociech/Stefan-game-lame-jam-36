#ifndef GAME_FLOOR_H_
#define GAME_FLOOR_H_

#include <game/SolidObject.h>

namespace game {

class Floor : public SolidObject {
private:
	bool isHitboxSet = false;
public:
	Floor(int counter);

	void update() override;
};

}

#endif // !GAME_FLOOR_H_
