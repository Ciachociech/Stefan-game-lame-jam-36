#include <drawable/Texture.h>

namespace drawable {

Texture::Texture(const std::string path) : path(std::move(path)) {
	if (!sf::Texture::loadFromFile(this->path)) {
		printf("Error! Cannot load file during setting texture.");
	}
}

const std::string& Texture::getPath() {
	return this->path;
}

void Texture::setSmoothMode(bool smoothMode) {
	sf::Texture::setSmooth(smoothMode);
}

}