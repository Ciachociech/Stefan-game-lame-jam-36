#ifndef AUDIO_MUSIC_H_
#define AUDIO_MUSIC_H_

#include <string>

#include <SFML/Audio.hpp>

namespace audio {

class Music : public sf::Music {
private:
	const std::string path;
	const std::string tag;
public:
	Music(const std::string tag, const std::string path);

	void setOffset(const sf::Time time);
	void setLoop(const bool isLooping);
	void setVolume(const float volume);
	void play();
	void pause();
	void stop();

	const std::string& getPath();
	const std::string& getTag();
};

}

#endif // !AUDIO_MUSIC_H_
