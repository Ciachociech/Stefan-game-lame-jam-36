#ifndef GAME_SOLIDOBJECT_H_
#define GAME_SOLIDOBJECT_H_

#include <string>

#include <game/Object.h>

namespace game {

class SolidObject : public Object {
private:
protected:
public:
	SolidObject(std::string tag, std::string texturePath) : Object(tag, texturePath) {}

	virtual void update() = 0;
};

}

#endif // !GAME_SOLIDOBJECT_H_
