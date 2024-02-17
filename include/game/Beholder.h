#ifndef GAME_BEHOLDER_H_
#define GAME_BEHOLDER_H_

#include <vector>

#include <game/SolidObject.h>

#include <SFML/Graphics.hpp>

#include <drawable/Sprite.h>

namespace game {

class Beholder : public SolidObject {
private:
	drawable::Sprite* sprite;

	drawable::Sprite raySprite;
	drawable::Texture rayTexture;
	std::vector<sf::FloatRect> rayHitboxes;
	bool isRayActive{ false };
	int rayCounter = 120;
public:
	Beholder(int counter, sf::Vector2f position);

	void update() override;
	drawable::Sprite& getRaySprite();
	const std::vector<sf::FloatRect>& getRayHitboxes();
	bool getIsRayActive();
};

}

#endif // !GAME_BEHOLDER_H_
