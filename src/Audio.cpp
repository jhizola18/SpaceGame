#include "Audio.h"

Audio::Audio()
	:
	Explosion()
{
	InitAudioDevice();
	menu =  LoadMusicStream("Sounds/Menu.mp3");
	Gameplay = LoadSound("Sounds/start.mp3");
	Dead = LoadSound("Sounds/player_death.mp3");
	timePlayed = 0.0f;

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
	PlayMusicStream(menu);
	SetMusicVolume(menu, 0.3f);
	
	return menu;

}

void Audio::soundStart()
{
	PlaySound(Gameplay);
	SetSoundVolume(Gameplay, 0.4f);
}

void Audio::soundGameOver()
{
	PlaySound(Dead);
	SetSoundVolume(Dead, 0.3f);
}
