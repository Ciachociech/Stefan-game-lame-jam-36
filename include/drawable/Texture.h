#ifndef DRAWABLE_TEXTURE_H_
#define DRAWABLE_TEXTURE_H_

#include <string>

#include <SFML/Graphics.hpp>

namespace drawable {

class Texture : public sf::Texture {
private:
	const std::string path;
public:
	Texture(const std::string path);

	const std::string& getPath();

	void setSmoothMode(bool smoothMode);
};

}

#endif