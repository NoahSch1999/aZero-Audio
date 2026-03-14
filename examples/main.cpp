#include "include/aZeroAudio.hpp"

#ifdef COMPILE_EXAMPLE
#include <Windows.h>
int main(int argc, char* argv[]) {
	
	aZero::Audio::AudioSystem audioSystem;
	aZero::Audio::AudioSource source = audioSystem.LoadAudio(std::string(AUDIO_SOURCE_PATH) + "boing.wav").value();
	source.Play();

	while(source.IsPlaying()){}

	return 0;
}
#endif