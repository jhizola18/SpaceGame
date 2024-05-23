#include "Audio.h"
#include "raygui.h"
#include <iostream>
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
	vfx_vol = 0.3f;
	bgm_vol = 0.3f;
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
	
	
	return menu;

}

void Audio::soundStart()
{
	PlaySound(Gameplay);
	
}

void Audio::soundGameOver()
{
	PlaySound(Dead);
	
}

void Audio::soundPause()
{
	PlaySound(Pause);
	
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
	
	

	return In_Game;
}

void Audio::soundShooting()
{
	PlaySound(Shooting);
	
}

void Audio::soundLevel()
{
	SetMusicVolume(menu, bgm_vol);
	SetMusicVolume(In_Game, bgm_vol);

	SetSoundVolume(Gameplay, vfx_vol);
	SetSoundVolume(Shooting, vfx_vol);
	SetSoundVolume(Pause, vfx_vol);
	SetSoundVolume(Dead, vfx_vol);


}



float& Audio::get_Vfx_vol()
{
	return vfx_vol;
}

float& Audio::get_bgm_vol()
{
	return bgm_vol;
}
