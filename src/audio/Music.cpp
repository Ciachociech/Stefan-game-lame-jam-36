#include <audio/Music.h>

namespace audio {
	
Music::Music(const std::string tag, const std::string path) : sf::Music(), tag(tag), path(path) {
	sf::Music::openFromFile(std::move(path));
}

void Music::setOffset(const sf::Time time) {
	sf::Music::setPlayingOffset(time);
}

void Music::setLoop(const bool isLooping) {
	sf::Music::setLoop(isLooping);
}

void Music::setVolume(const float volume) {
	sf::Music::setVolume(volume);
}

void Music::play() {
	sf::Music::play();
}

void Music::pause() {
	sf::Music::pause();
}

void Music::stop() {
	sf::Music::stop();
}

const std::string& Music::getPath() {
	return this->path;
}

const std::string& Music::getTag() {
	return this->tag;
}



}