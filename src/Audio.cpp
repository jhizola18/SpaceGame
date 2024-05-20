#include "Audio.h"

int fps_Sound = 0;

Audio::Audio()
{
	InitAudioDevice();
	menu =  LoadMusicStream("Sounds/Menu.mp3");
	Gameplay = LoadSound("Sounds/start.mp3");
	Dead = LoadSound("Sounds/player_death.mp3");
	In_Game = LoadMusicStream("Sounds/soundGameplay.mp3");
	Pause = LoadSound("Sounds/soundPause.mp3");
	Shooting = LoadSound("Sounds/soundShooting.mp3");
}

Audio::~Audio() noexcept
{
	UnloadMusicStream(menu);
	UnloadSound(Gameplay);
	UnloadSound(Dead);
	UnloadMusicStream(In_Game);

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

void Audio::soundPause()
{
	PlaySound(Pause);
	SetSoundVolume(Pause, 0.4f);
}

Music Audio::soundInGame()
{
	fps_Sound++;
	
	if (fps_Sound < 3825)
	{
		PlayMusicStream(In_Game);
	}
	else {
		fps_Sound = 0;
	}
	
	SetMusicVolume(In_Game, 0.3f);

	return In_Game;
}

void Audio::soundShooting()
{
	PlaySound(Shooting);
	SetSoundVolume(Shooting, 0.3f);
}
