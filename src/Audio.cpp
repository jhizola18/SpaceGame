#include "Audio.h"

Audio::Audio()
	:
	menu(),
	Gameplay(),
	Dead(),
	Explosion()
{
	
	InitAudioDevice();
}

Audio::~Audio() noexcept
{
	UnloadMusicStream(menu);
	UnloadSound(Gameplay);
	UnloadSound(Dead);
	UnloadSound(Explosion);
}

Music Audio::soundMenu()
{
	menu = LoadMusicStream("Sounds/Menu.mp3");
	if (!IsMusicReady(menu))
	{
		DrawText("Error Loading Music", 300, 200, 15, WHITE);
	}
	else {
		PlayMusicStream(menu);

		SetMusicVolume(menu, 0.1f);
	}

	return menu;

}
