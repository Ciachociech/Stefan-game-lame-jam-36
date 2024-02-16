#ifndef AUDIO_SOUNDBUFFER_H_
#define AUDIO_SOUNDBUFFER_H_

#include <string>

#include <SFML/Audio.hpp>

namespace audio {

class SoundBuffer : public sf::SoundBuffer {
private:
	const std::string path;
public:
	SoundBuffer(const std::string path);

	const std::string& getPath();
};

}

#endif // !AUDIO_SOUNDBUFFER_H_
