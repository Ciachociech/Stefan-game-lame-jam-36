#ifndef GAME_BEHOLDER_H_
#define GAME_BEHOLDER_H_

#include <vector>

#include <game/SolidObject.h>

#include <drawable/Sprite.h>

namespace game {

class Beholder : public SolidObject {
private:
	drawable::Sprite* sprite;

	drawable::Sprite raySprite;
	drawable::Texture rayTexture;
public:
	Beholder(int counter, sf::Vector2f position);

	void update() override;
	drawable::Sprite& getRaySprite();
};

}

#endif // !GAME_BEHOLDER_H_
