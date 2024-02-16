#ifndef AUDIO_SOUND_H_
#define AUDIO_SOUND_H_

#include <string>

#include <audio/SoundBuffer.h>

#include <SFML/Audio.hpp>

namespace audio {

class Sound : public sf::Sound {
private:
	const std::string tag;
public:
	Sound(const std::string tag, const SoundBuffer& buffer);
	Sound(const std::string tag);

	void setBuffer(const SoundBuffer& buffer);
	void setOffset(const sf::Time time);
	void setLoop(const bool isLooping);
	void setVolume(const float volume);
	void play();
	void pause();
	void stop();

	const std::string& getTag();
};

}

#endif // !AUDIO_SOUND_H_
