#include "MenuManager.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "enums.h"
#include "iostream"
#include "fstream"

int HighScore;

Menu::Menu()
{
	Image imahe = LoadImage("Image/game_bg.png");
	background = LoadTextureFromImage(imahe);
}

Menu::~Menu()
{
	UnloadTexture(background);
}

void Menu::MainMenu()
{
	GuiPanel({0,0,(float)GetScreenWidth(), (float)GetScreenHeight()},"Sample");
}

void Menu::DrawCursor()
{
	DrawRectangleLines(varHolder::cursorPosition().x, varHolder::cursorPosition().y, 12, 12, WHITE);
}

bool Menu::MenuBtn()
{
	if (GuiButton({ (float)GetScreenWidth() / 3, (float)GetScreenHeight() / 3, 200.0f,50.0f },GuiIconText(ICON_PLAYER_PLAY,"Start")))
	{
		return true;
	}

	return false;
}



bool Menu::OptionBtn()
{
	if (GuiButton({ (float)GetScreenWidth() / 3, (float)GetScreenHeight() / 2, 200.0f,50.0f }, GuiIconText(ICON_GEAR, "Option")))
	{
		return true;
	}
	
	return false;
	
}
bool Menu::BackBtn()
{
	if (GuiButton({ 20.0f, 20.0f, 50.0f,50.0f }, GuiIconText(ICON_PLAYER_PREVIOUS, " ")))
	{
		return true;
	}

	return false;
}

bool Menu::PauseBtn()
{
	if (GuiButton({ 20.0f, 20.0f, 50.0f,50.0f }, GuiIconText(ICON_PLAYER_PAUSE, " ")))
	{
			return true;
	}
	return false;
}

bool Menu::PlayBtn()
{
	if (GuiButton({ 20.0f, 20.0f, 50.0f,50.0f }, GuiIconText(ICON_PLAYER_PLAY, " ")))
	{
		return true;
	}
	return false;
}


bool Menu::Replay()
{

	DrawText("GAME OVER!", (float)GetScreenWidth() / 2.5, (float)GetScreenHeight() /2.5, 20, WHITE);

	if (GuiButton({ 210, (float)GetScreenHeight() / 2, 200.0f,50.0f }, GuiIconText(ICON_PLAYER_PREVIOUS, "REPLAY")))
	{
		return true;
	}
	return false;
}

bool Menu::MenuBackBtn()
{
	if (GuiButton({ 210, 550, 200.0f,50.0f }, GuiIconText(ICON_PLAYER_PLAY, "RETURN TO MAIN MENU")))
	{
		return true;
	}

	return false;
}

void Menu::Background(int posx, int posy, Color tint)
{
	//Open the file and read what's inside it
	std::ifstream OpenFile("High-score.txt");
	if (OpenFile.is_open())
	{
		OpenFile >> HighScore;
		
		OpenFile.close();
	};
	DrawTexture(background, posx, posy, tint);
	DrawText(TextFormat("Score: %i", Destroyed), 50, 750, 15, WHITE);
	DrawText(TextFormat("High-Score: %i", HighScore), 50, 700, 15, WHITE);
}

void Menu::Player_Score()
{
	if (Destroyed > HighScore && gameOver)
	{
		//Create a File and write the High Score for a Player
		std::ofstream CreatedFile("High-score.txt");
		if (CreatedFile.is_open())
		{
			CreatedFile << Destroyed;
			CreatedFile.close();
		}
		
		//Open the Created File to read the score inside and store
		std::ifstream OpenFile("High-score.txt");
		if (OpenFile.is_open())
		{
			OpenFile >> Destroyed;
			HighScore = Destroyed;
			
			OpenFile.close();
		}
		
	}
}




