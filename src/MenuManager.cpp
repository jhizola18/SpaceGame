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
	title = LoadImage("Image/PEW_PEW_GAME.gif");
	titleAnim = LoadTextureFromImage(title);
	colored = varHolder::ship_colors();
	PositionTitle = { 80.0, 200.0 };
	fontsize = 0.5f;
}

Menu::~Menu()
{
	UnloadTexture(background);
	UnloadImage(title);
	UnloadTexture(titleAnim);
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
	DrawTextureEx(titleAnim, PositionTitle, 0.0f, fontsize, LIGHTGRAY);
	
	if (GuiButton({ (float)GetScreenWidth() / 3, (float)GetScreenHeight() / 2, 200.0f,50.0f },GuiIconText(ICON_PLAYER_PLAY,"Start")))
	{
		return true;
	}

	return false;
}



bool Menu::OptionBtn()
{
	if (GuiButton({ (float)GetScreenWidth() / 3, ((float)GetScreenHeight() / 2) + 100, 200.0f,50.0f}, GuiIconText(ICON_GEAR, "Option")))
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
	DrawTexture(background, posx, posy, tint);
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

void Menu::showScore()
{
	std::ifstream OpenFile("High-score.txt");
	if (OpenFile.is_open())
	{
		OpenFile >> HighScore;

		OpenFile.close();
	};
	DrawText(TextFormat("Score: %i", Destroyed), 50, 750, 15, WHITE);
	DrawText(TextFormat("High-Score: %i", HighScore), 50, 700, 15, WHITE);
}

void Menu::healthbar(float posx, float posy,float& health)
{
	GuiProgressBar({posx - 15, posy + 10 ,70, 10}, NULL, NULL, &health, 0.0f, 100.0f);
}


void Menu::soundSettings(float& vfx_vol, float& bgm_vol)
{
	
	DrawText("SOUND SETTINGS", 220, 200, 20, WHITE);

	DrawText("Sound Effect: ", 120, 320, 20, WHITE);
	GuiSliderBar({ 120, 350, 180, 20 }, "Min", "Max", &vfx_vol, 0.0f, 0.8f);
	
	DrawText("Background Music: ", 120, 420, 20, WHITE);
	GuiSliderBar({ 120, 450, 180, 20 }, "Min", "Max", &bgm_vol, 0.0f, 0.8f);
}

int Menu::colorSettings(Player_Ship& ship)
{
	if (game_state == Option)
	{

		if (IsKeyPressed(KEY_Q))
		{
			ship.getship_color()--;
			if (ship.getship_color() < 0)
			{
				ship.getship_color() = 0;
			}
		}
		if (IsKeyPressed(KEY_E))
		{
			ship.getship_color()++;
			if (ship.getship_color() > 4)
			{
				ship.getship_color() = 4;
			}
		}
	}
		
	return ship.getship_color();
	
}

void Menu::colorSettingsGUI(Player_Ship& ship)
{
	DrawText("SHIP COLOR", 220, 500, 20, WHITE);

	DrawText("Ship Color: ", 120, 550, 20, WHITE);
	DrawText("Q", 240, 630, 20, WHITE);
	DrawTriangle({ 300, 620 }, { 280 , 650 }, { 320, 650 }, colored[ship.getship_color()]);
	DrawText("E", 360, 630, 20, WHITE);
}




