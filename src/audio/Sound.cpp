#include <audio/Sound.h>

namespace audio {

Sound::Sound(const std::string tag, const SoundBuffer& buffer) : sf::Sound(), tag() {
	this->setBuffer(buffer);
}

Sound::Sound(const std::string tag) : sf::Sound(), tag() {}

void Sound::setBuffer(const SoundBuffer& buffer) {
	sf::Sound::setBuffer(buffer);
}

void Sound::setOffset(const sf::Time time) {
	sf::Sound::setPlayingOffset(time);
}

void Sound::setLoop(const bool isLooping) {
	sf::Sound::setLoop(isLooping);
}

void Sound::setVolume(const float volume) {
	sf::Sound::setVolume(volume);
}

void Sound::play() {
	sf::Sound::play();
}

void Sound::pause() {
	sf::Sound::pause();
}

void Sound::stop() {
	sf::Sound::stop();
}

const std::string& Sound::getTag() {
	return this->tag;
}

}