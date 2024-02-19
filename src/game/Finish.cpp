#include <game/Finish.h>

namespace game {
	
Finish::Finish() : SolidObject("finish", "assets/sprites/finish.png") {}

void Finish::update() {
	if (!isHitboxSet) {
		setHitbox(getSprite().getGlobalBounds());
	}
}

}