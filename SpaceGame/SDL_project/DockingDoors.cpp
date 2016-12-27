#include "stdafx.h"
#include "DockingDoors.h"


DockingDoors::DockingDoors() : overlayTexture("Resources\\oxygen.png")
{
}


DockingDoors::~DockingDoors()
{
}

void DockingDoors::placeDockingDoors(SDL_Renderer* renderer, Level& level)
{
	changeOrientation();

	renderOverlay(renderer, level);


}

void DockingDoors::placeEntryPath(Level& level, int xPos, int yPos)
{
	if (xPos > 0 && xPos < level.getLevelWidth() && yPos > 0 && yPos < level.getLevelHeight())
		level.grid[xPos / level.getCellSize()][yPos / level.getCellSize()]->isDockingPath = true;
}

void DockingDoors::renderOverlay(SDL_Renderer* renderer, Level& level)
{
	// left
	int cellSize = level.getCellSize();
	int mouseX, mouseY;
	bool placeOnlyOnce = true;
	if (dockOrientation == 0)
	{
		SDL_GetMouseState(&mouseX, &mouseY);

		for (int x = -level.getLevelWidth(); x < 0; x++)
		{
			for (int y = -1; y < 2; y++)
			{
				int xPos = mouseX + x * level.getCellSize();
				int yPos = mouseY + y * level.getCellSize();
				overlayTexture.render(renderer, xPos, yPos, level.getCellSize(), level.getCellSize());
				if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT))
				{
					if (placeOnlyOnce)
					{
						placeEntryPath(level, xPos, yPos);
						placeOnlyOnce = false;
					}
					
				}
			}

		}
	}

	// Right
	if (dockOrientation == 1)
	{
		SDL_GetMouseState(&mouseX, &mouseY);

		for (int x = 0; x < level.getLevelWidth(); x++)
		{
			for (int y = -1; y < 2; y++)
			{
				int xPos = mouseX + x * level.getCellSize();
				int yPos = mouseY + y * level.getCellSize();
				overlayTexture.render(renderer, xPos, yPos, level.getCellSize(), level.getCellSize());
				if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT))
				{
					if (placeOnlyOnce)
					{
						placeEntryPath(level, xPos, yPos);
						placeOnlyOnce = false;
					}
				}
			}
		}
	}
}

void DockingDoors::changeOrientation()
{
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	// Left
	if (state[SDL_SCANCODE_1])
	{
		dockOrientation = 0;
	}
	// Right
	if (state[SDL_SCANCODE_2])
	{
		dockOrientation = 1;
	}
}