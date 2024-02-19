#ifndef GAME_FINISH_H_
#define GAME_FINISH_H_

#include <game/SolidObject.h>

namespace game {

class Finish : public SolidObject {
private:
	bool isHitboxSet = false;
public:
	Finish();

	void update() override;
};

}

#endif // !GAME_FINISH_H_
