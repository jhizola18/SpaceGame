#include "MenuManager.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "enums.h"

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

void Menu::Background(int posx, int posy, Color tint)
{
	DrawTexture(background ,posx, posy, tint);
}




