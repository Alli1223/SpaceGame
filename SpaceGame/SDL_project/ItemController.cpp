#include "stdafx.h"
#include "ItemController.h"
#include "Character.h"
#include "level.h"
#include "Oxygen.h"



ItemController::ItemController()
{
}


ItemController::~ItemController()
{
}

void ItemController::Interaction(Level& grid, Character& character, Oxygen& oxygen)
{
	
	//Gets the player X and Y values
	int pX = character.getX();
	int pY = character.getY();
	int playerX = pX / grid.getCellSize();
	int playerY = pY / grid.getCellSize();

	// If the player walks near to the door, open it
	for (int x = -2; x < 2; x++)
	{
		for (int y = -2; y < 2; y++)
		{
			if (grid.grid[playerX + x][playerY + y]->isOpenDoor == true)
			{
				grid.grid[playerX + x][playerY + y]->isOpenDoor = false;
				grid.grid[playerX + x][playerY + y]->isClosedDoor = true;
			}
		}
	}

	// If the player walks over an oxygen tank, remove it
	if (grid.grid[playerX][playerY]->isOxygenTank == true)
	{
		int currentOxygen = oxygen.getOxygenReserves();
		oxygen.setOxygenReserves(currentOxygen + 1000);
		grid.grid[playerX][playerY]->isOxygenTank = false;
	}
	
	if (grid.grid[playerX][playerY]->isHealthPack == true)
	{
		grid.grid[playerX][playerY]->isHealthPack = false;	
		character.health = 100;
	}

	
	



}
