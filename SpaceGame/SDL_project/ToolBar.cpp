#include "stdafx.h"
#include "ToolBar.h"


ToolBar::ToolBar()

	: toolBarBackground("Resources\\Toolbar\\toolbarBackground.png"),
	roomCell("Resources\\roomSprites\\center.png"), emptyCell("Resources\\roomSprites\\emptyCell.png"), 
	emptyCellIcon("Resources\\Toolbar\\empty.png"),
	DoorTexture("Resources\\door_sprite.png")
{

}


ToolBar::~ToolBar()
{
}

void ToolBar::RenderToolbar(SDL_Renderer* renderer, int WINDOW_WIDTH, int WINDOW_HEIGHT, int mouseX, int mouseY)
{
	int toolbarSizeX = WINDOW_WIDTH - (WINDOW_WIDTH / 4);
	int toolbarSizeY = WINDOW_HEIGHT / 15;
	int toolbarXpos = WINDOW_WIDTH / 2;
	int toolbarYpos = (WINDOW_HEIGHT - toolbarSizeY);

	int iconOneXpos = toolbarXpos - (toolbarXpos / 2);
	int iconOneYpos = toolbarYpos;

	int iconTwoXpos = toolbarXpos - (toolbarXpos / 4);
	int iconTwoYpos = toolbarYpos;

	int iconThreeXpos = toolbarXpos;
	int iconThreeYpos = toolbarYpos;

	int iconFourXpos = toolbarXpos + (toolbarSizeX * 2);
	int iconFourYpos = toolbarYpos;

	//toolBarBackground.alterTransparency(20);
	toolBarBackground.render(renderer, toolbarXpos, toolbarYpos, toolbarSizeX, toolbarSizeY);
	roomCell.render(renderer, iconOneXpos, iconOneYpos, toolbarIconSize, toolbarIconSize);

	// ICON ONE
	if (mouseX > iconOneXpos - (toolbarIconSize / 2) && mouseX < iconOneXpos + (toolbarIconSize / 2) && mouseY > toolbarYpos - toolbarIconSize / 2 && mouseY < toolbarYpos + toolbarSizeY / 2)
	{
		roomCell.render(renderer, iconOneXpos, iconOneYpos, toolbarIconSize + 10, toolbarIconSize + 10);
		if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			setToolbarSelection(1);
		}
	}

	// ICON TWO
	emptyCellIcon.render(renderer, iconTwoXpos, iconTwoYpos, toolbarIconSize, toolbarIconSize);
	if (mouseX > iconTwoXpos - (toolbarIconSize / 2) && mouseX < iconTwoXpos + (toolbarIconSize / 2) && mouseY > toolbarYpos - toolbarIconSize / 2 && mouseY < toolbarYpos + toolbarSizeY / 2)
	{
		emptyCellIcon.render(renderer, iconTwoXpos, iconTwoYpos, toolbarIconSize + 10, toolbarIconSize + 10);
		if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			setToolbarSelection(2);
		}
	}

	// ICON THREE
	DoorTexture.render(renderer, iconThreeXpos, iconThreeYpos, toolbarIconSize, toolbarIconSize);
	if (mouseX > iconThreeXpos - (toolbarIconSize / 2) && mouseX < iconThreeXpos + (toolbarIconSize / 2) && mouseY > toolbarYpos - toolbarIconSize / 2 && mouseY < toolbarYpos + toolbarSizeY / 2)
	{
		DoorTexture.render(renderer, iconThreeXpos, iconThreeYpos, toolbarIconSize + 10, toolbarIconSize + 10);
		if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			setToolbarSelection(3);
		}
	}

	// ICON FOUR
		
	
}

void ToolBar::ToolBarFunctionality(Level& room, RoomDesign& designroom, int mouse_X, int mouse_Y)
{
	int toolbarSelection = getToolbarSelection();
	//Toolbar functionality
	if (SDL_GetMouseState(&mouse_X, &mouse_Y) & SDL_BUTTON(SDL_BUTTON_LEFT) && toolbarSelection == 1)
	{
		//TODO: Fix boundy error
		for (int mX = (mouse_X / room.getCellSize()) - 1; mX < (mouse_X / room.getCellSize()) + 2; mX++)
		{
			for (int mY = (mouse_Y / room.getCellSize()) - 2; mY < (mouse_Y / room.getCellSize()) + 1; mY++)
			{
				room.grid[mX][mY]->isRoom = true;
			}
		}
		for (int mX = (mouse_X / room.getCellSize()) - 3; mX < (mouse_X / room.getCellSize()) + 3; mX++)
		{
			for (int mY = (mouse_Y / room.getCellSize()) - 3; mY < (mouse_Y / room.getCellSize()) + 3; mY++)
			{
				designroom.designRoom(room, mX, mY);

			}
		}
	}

	if (SDL_GetMouseState(&mouse_X, &mouse_Y) & SDL_BUTTON(SDL_BUTTON_LEFT) && toolbarSelection == 2)
	{
		room.grid[mouse_X / room.getCellSize()][mouse_Y / room.getCellSize()]->isRoom = false;
		for (int mX = (mouse_X / room.getCellSize()) - 3; mX < (mouse_X / room.getCellSize()) + 3; mX++)
		{
			for (int mY = (mouse_Y / room.getCellSize()) - 3; mY < (mouse_Y / room.getCellSize()) + 3; mY++)
			{
				designroom.designRoom(room, mX, mY);
			}
		}
	}
	if (SDL_GetMouseState(&mouse_X, &mouse_Y) & SDL_BUTTON(SDL_BUTTON_LEFT) && toolbarSelection == 3)
	{
		room.grid[mouse_X / room.getCellSize()][mouse_Y / room.getCellSize()]->isOpenDoor = true;
	}

	if (SDL_GetMouseState(&mouse_X, &mouse_Y) & SDL_BUTTON(SDL_BUTTON_MIDDLE))
	{
		room.grid[mouse_X / room.getCellSize()][mouse_Y / room.getCellSize()]->oxygenLevel = 100;
	}
}