#include <game/Beholder.h>

namespace game {

Beholder::Beholder(int counter) : SolidObject("floor" + std::to_string(counter), "assets/sprites/WIP32x32.png") {}

void Beholder::update() {

}

}