#include "stdafx.h"
#include "PlayerInteraction.h"
#include "Character.h"
#include "level.h"
#include "Oxygen.h"



PlayerInteraction::PlayerInteraction()
{
}


PlayerInteraction::~PlayerInteraction()
{
}

void PlayerInteraction::Interaction(Level& grid, Character& character, Oxygen& oxygen)
{
	
	//Gets the player X and Y values
	int pX = character.getX();
	int pY = character.getY();
	int playerX = pX / grid.getCellSize();
	int playerY = pY / grid.getCellSize();

	// If the player walks near to the door, open it
	if (playerX - doorOpenDistance > 0 && playerX + doorOpenDistance < grid.getLevelWidth() && playerY - doorOpenDistance > 0 && playerY + doorOpenDistance)
	{
		for (int x = -doorOpenDistance; x < doorOpenDistance; x++)
		{
			for (int y = -doorOpenDistance; y < doorOpenDistance; y++)
			{
				if (x > (-doorOpenDistance + 1) && y >(-doorOpenDistance + 1))
				{
					if (grid.grid[playerX + x][playerY + y]->isOpenDoor == true)
					{
						grid.grid[playerX + x][playerY + y]->isOpenDoor = false;
						grid.grid[playerX + x][playerY + y]->isClosedDoor = true;
					}
				}
			}

			if (grid.grid[playerX - doorOpenDistance][playerY + x]->isClosedDoor)
			{
				grid.grid[playerX - doorOpenDistance][playerY + x]->isClosedDoor = false;
				grid.grid[playerX - doorOpenDistance][playerY + x]->isOpenDoor = true;
			}
			else if (grid.grid[playerX + 3][playerY + x]->isClosedDoor)
			{
				grid.grid[playerX + doorOpenDistance][playerY + x]->isClosedDoor = false;
				grid.grid[playerX + doorOpenDistance][playerY + x]->isOpenDoor = true;
			}
			if (grid.grid[playerX + x][playerY + doorOpenDistance]->isClosedDoor)
			{
				grid.grid[playerX + x][playerY + doorOpenDistance]->isClosedDoor = false;
				grid.grid[playerX + x][playerY + doorOpenDistance]->isOpenDoor = true;
			}
			else if (grid.grid[playerX + x][playerY - 3]->isClosedDoor)
			{
				grid.grid[playerX + x][playerY - doorOpenDistance]->isClosedDoor = false;
				grid.grid[playerX + x][playerY - doorOpenDistance]->isOpenDoor = true;
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
