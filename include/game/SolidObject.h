#ifndef GAME_SOLIDOBJECT_H_
#define GAME_SOLIDOBJECT_H_

#include <string>

#include <drawable/Sprite.h>
#include <drawable/Texture.h>
#include <window/JoystickInput.h>
#include <window/KeyboardInput.h>

namespace game {

class SolidObject {
private:
	drawable::Sprite sprite;
	drawable::Texture texture;

	std::string tag_;
protected:
	SolidObject(std::string tag, std::string texturePath) : sprite(tag + "Sprite"), texture(texturePath) { sprite.setTexture(texture); }

	drawable::Sprite& getSprite() { return sprite; }
public:
	virtual void update() = 0;

	const std::string& getTag() { return tag_; }
};

}

#endif // !GAME_SOLIDOBJECT_H_
