#include "stdafx.h"
#include "ToolBar.h"


ToolBar::ToolBar()

	: toolBarBackground("Resources\\Toolbar\\toolbarBackground.png"),
	roomCell("Resources\\roomSprites\\center.png"), emptyCell("Resources\\roomSprites\\emptyCell.png"), 
	emptyCellIcon("Resources\\Toolbar\\empty.png"),
	DoorTexture("Resources\\door_sprite.png"),
	HydroponicsIconTexture("Resources\\Toolbar\\hydroponicsIcon.png")
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
	
	int toobarIconXPos = toolbarXpos - (toolbarSizeX / 2);
	int iconOneXpos = toolbarXpos - (toolbarXpos / 2);
	int iconOneYpos = toolbarYpos;
	toobarIconXPos = toolbarXpos + toolbarIconSize * 2;

	int iconTwoXpos = toobarIconXPos;
	int iconTwoYpos = toolbarYpos;
	toobarIconXPos = toobarIconXPos + toolbarIconSize * 2;

	int iconThreeXpos = toobarIconXPos;
	int iconThreeYpos = toolbarYpos;
	toobarIconXPos = toobarIconXPos + toolbarIconSize * 2;

	int iconFourXpos = toobarIconXPos;
	int iconFourYpos = toolbarYpos;

	//toolBarBackground.alterTransparency(20);
	toolBarBackground.render(renderer, toolbarXpos, toolbarYpos, toolbarSizeX, toolbarSizeY);


	roomCell.render(renderer, iconOneXpos, iconOneYpos, toolbarIconSize, toolbarIconSize);
	// ICON ONE
	if (mouseX > iconOneXpos - (toolbarIconSize / 2) && mouseX < iconOneXpos + (toolbarIconSize / 2) && mouseY > toolbarYpos - toolbarIconSize / 2 && mouseY < toolbarYpos + toolbarSizeY / 2)
	{
		roomCell.render(renderer, iconOneXpos, iconOneYpos, toolbarIconSize + mouseOverSizeIncrease, toolbarIconSize + mouseOverSizeIncrease);
		if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			setToolbarSelection(1);
		}
	}

	// ICON TWO
	emptyCellIcon.render(renderer, iconTwoXpos, iconTwoYpos, toolbarIconSize, toolbarIconSize);
	if (mouseX > iconTwoXpos - (toolbarIconSize / 2) && mouseX < iconTwoXpos + (toolbarIconSize / 2) && mouseY > toolbarYpos - toolbarIconSize / 2 && mouseY < toolbarYpos + toolbarSizeY / 2)
	{
		emptyCellIcon.render(renderer, iconTwoXpos, iconTwoYpos, toolbarIconSize + mouseOverSizeIncrease, toolbarIconSize + mouseOverSizeIncrease);
		if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			setToolbarSelection(2);
		}
	}

	// ICON THREE
	if (numberOfItem3 > 0)
	{
		DoorTexture.render(renderer, iconThreeXpos, iconThreeYpos, toolbarIconSize, toolbarIconSize);
		if (mouseX > iconThreeXpos - (toolbarIconSize / 2) && mouseX < iconThreeXpos + (toolbarIconSize / 2) && mouseY > toolbarYpos - toolbarIconSize / 2 && mouseY < toolbarYpos + toolbarSizeY / 2)
		{
			DoorTexture.render(renderer, iconThreeXpos, iconThreeYpos, toolbarIconSize + mouseOverSizeIncrease, toolbarIconSize + mouseOverSizeIncrease);
			if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				setToolbarSelection(3);
			}
		}
	}

	// ICON FOUR

	HydroponicsIconTexture.render(renderer, iconFourXpos, iconFourYpos, toolbarIconSize, toolbarIconSize);
	if (mouseX > iconFourXpos - (toolbarIconSize / 2) && mouseX < iconFourXpos + (toolbarIconSize / 2) && mouseY > toolbarYpos - toolbarIconSize / 2 && mouseY < toolbarYpos + toolbarSizeY / 2)
	{
		if (numberOfItem4 > 0)
		{
			HydroponicsIconTexture.render(renderer, iconFourXpos, iconFourYpos, toolbarIconSize + mouseOverSizeIncrease, toolbarIconSize + mouseOverSizeIncrease);
			if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				setToolbarSelection(4);
			}
		}
	}

}

void ToolBar::ToolBarFunctionality(Level& room, RoomDesign& designroom, SDL_Renderer* renderer,  int mouse_X, int mouse_Y)
{
	int toolbarSelection = getToolbarSelection();
	//Toolbar functionality
	
	if (SDL_GetMouseState(&mouse_X, &mouse_Y) & SDL_BUTTON(SDL_BUTTON_LEFT) && toolbarSelection == 1)
	{
		if (numberOfItem1 > 0)
		{
			if (mouse_X / room.getCellSize() - 3 > 0 && mouse_X / room.getCellSize() + 3 < room.getLevelWidth() && mouse_Y / room.getCellSize() - 3 > 0 && mouse_Y / room.getCellSize() + 3 < room.getLevelHeight())
			{
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
		}
	}
	// Place Item 2
	
	if (SDL_GetMouseState(&mouse_X, &mouse_Y) & SDL_BUTTON(SDL_BUTTON_LEFT) && toolbarSelection == 2)
	{
		if (numberOfItem2 > 0)
		{
			room.grid[mouse_X / room.getCellSize()][mouse_Y / room.getCellSize()]->isRoom = false;
			room.grid[mouse_X / room.getCellSize()][mouse_Y / room.getCellSize()]->isOpenDoor = false;
			room.grid[mouse_X / room.getCellSize()][mouse_Y / room.getCellSize()]->isClosedDoor = false;
			for (int mX = (mouse_X / room.getCellSize()) - 4; mX < (mouse_X / room.getCellSize()) + 4; mX++)
			{
				for (int mY = (mouse_Y / room.getCellSize()) - 4; mY < (mouse_Y / room.getCellSize()) + 4; mY++)
				{
					designroom.designRoom(room, mX, mY);
				}
			}
		}
	}
	// Place Item 3
	if (SDL_GetMouseState(&mouse_X, &mouse_Y) & SDL_BUTTON(SDL_BUTTON_LEFT) && toolbarSelection == 3)
	{
		if (numberOfItem3 > 0 && !room.grid[mouse_X / room.getCellSize()][mouse_Y / room.getCellSize()]->isOpenDoor)
		{
			room.grid[mouse_X / room.getCellSize()][mouse_Y / room.getCellSize()]->isOpenDoor = true;
			numberOfItem3--;
		}
	}
	
	if (SDL_GetMouseState(&mouse_X, &mouse_Y) & SDL_BUTTON(SDL_BUTTON_LEFT) && toolbarSelection == 4)
	{
		
		if (numberOfItem4 > 0)
		{
			/*
			Hydroponics hydroponics;
			hydroponics.setX(mouse_X);
			hydroponics.setY(mouse_Y);
			
			hydroponics.spawnItem(renderer, room, hydroponics, mouse_X, mouse_Y);
			numberOfItem4--;
			*/
		}
	}
	
	

	if (SDL_GetMouseState(&mouse_X, &mouse_Y) & SDL_BUTTON(SDL_BUTTON_MIDDLE))
	{
		room.grid[mouse_X / room.getCellSize()][mouse_Y / room.getCellSize()]->oxygenLevel = 100;
	}
}