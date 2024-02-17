#ifndef GAME_BEHOLDER_H_
#define GAME_BEHOLDER_H_

#include <vector>

#include <game/SolidObject.h>

namespace game {

class Beholder : public SolidObject {
private:

public:
	Beholder(int counter);

	void update() override;
};

}

#endif // !GAME_BEHOLDER_H_
