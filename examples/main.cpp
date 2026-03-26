#ifdef COMPILE_EXAMPLE
#include <iostream>
#include <chrono>
#include "include/aZeroAudio.hpp"

int main(int argc, char* argv[]) {
	
	// Init the audio engine
	aZero::Audio::AudioEngine audioEngine;

	// Load a source with streaming enabled
	std::optional<aZero::Audio::AudioSource> sourceOpt = audioEngine.CreateFromFile(std::string(AUDIO_SOURCE_PATH) + "drums.wav", true);
	if (sourceOpt.has_value()) { // If the source was loaded

		// Move, since copy ops are prohibited
		aZero::Audio::AudioSource source = std::move(sourceOpt.value());

		// Just some stuff for the example
		using clock = std::chrono::high_resolution_clock;
		auto lastTime = clock::now();
		float angle = 0.f;
		float speed = 1500.f;
		float radius = 5.f;
		//

		// Set the listeners forward and position
		audioEngine.SetListenerForward(0, 0, 1);
		audioEngine.SetListenerPosition(0, 0, 0.f);

		// Start playing the source
		source.Play();

		while (source.IsPlaying()) { // Loops as long as the audio is playing

			// Just some stuff for the example
			auto currentTime = clock::now();
			std::chrono::duration<float> delta = currentTime - lastTime;
			lastTime = currentTime;
			float deltaTime = delta.count();
			//

			// Rotate the audiosource around origo
			float x = radius * cos(angle);
			float y = radius * sin(angle);
			source.SetWorldPosition(x, y, 0);

			angle += speed * deltaTime;
		}
	}

	return 0;
}
#endif