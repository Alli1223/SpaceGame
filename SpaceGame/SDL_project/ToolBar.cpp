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
		
	
}