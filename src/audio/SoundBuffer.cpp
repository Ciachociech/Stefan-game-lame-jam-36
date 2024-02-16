#include <audio/SoundBuffer.h>

namespace audio {

SoundBuffer::SoundBuffer(const std::string path) : sf::SoundBuffer(), path(std::move(path)) {
	sf::SoundBuffer::loadFromFile(this->path);
}

const std::string& SoundBuffer::getPath() {
	return this->path;
}



}