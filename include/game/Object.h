#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <string>

#include <drawable/Sprite.h>
#include <drawable/Texture.h>

namespace game {

class Object {
private:
	drawable::Sprite sprite;
	drawable::Texture texture;

	std::string tag_;
public:
	Object(std::string tag, std::string texturePath) : sprite(tag + "Sprite"), texture(texturePath) { sprite.setTexture(texture); }

	const std::string& getTag() { return tag_; }
	drawable::Sprite& getSprite() { return sprite; }
};

}

#endif // !GAME_OBJECT_H_
