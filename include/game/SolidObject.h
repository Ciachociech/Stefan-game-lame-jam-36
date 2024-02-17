#ifndef GAME_SOLIDOBJECT_H_
#define GAME_SOLIDOBJECT_H_

#include <string>

#include <game/Object.h>

namespace game {

class SolidObject : public Object {
private:
	sf::FloatRect hitbox;
protected:
	void setHitbox(sf::FloatRect hitbox) { this->hitbox = hitbox; }
public:
	SolidObject(std::string tag, std::string texturePath) : Object(tag, texturePath) {}

	virtual void update() = 0;

	const sf::FloatRect& getHitbox() { return hitbox; }
};

}

#endif // !GAME_SOLIDOBJECT_H_
