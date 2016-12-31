#include "stdafx.h"
#include "ShipManager.h"


ShipManager::ShipManager()
{
}


ShipManager::~ShipManager()
{
}

void ShipManager::createShip(std::vector<Ship>& allShips)
{
	Ship shipOne;
	allShips.push_back(shipOne);
	shipAlreadySpawned = true;
}

void ShipManager::shipTimer(Level& level, std::vector<Ship>& allShips)
{

	if (!shipAlreadySpawned)
	{
		createShip(allShips);
	}

	if (!thereIsDockingPath)
	{
		for (int i = 0; i < allShips.size(); i++)
			findShipSpawn(level, allShips[i]);
	}

	for (int i = 0; i < allShips.size(); i++)
	{
		if (thereIsDockingPath && !allShips[i].isDocked)
		{
			moveShipToDock(level, allShips[i], 1);
		}
	}
}

void ShipManager::renderShip(std::vector<Ship>& allships, SDL_Renderer* renderer)
{
	for each(auto ship in allships)
	{
		ship.RenderShip(renderer, ship);
	}
}



void ShipManager::findShipSpawn(Level& level, Ship& ship)
{
	// find and set intital ship spawn position
	for (int y = 0; y < level.getLevelHeight(); y++)
	{
		if (level.grid[0][y]->isDockingPath)
		{
			ship.setX(0);
			ship.setY(y * level.getCellSize() + (level.getCellSize() / 2));
			thereIsDockingPath = true;
			ship.shipPlacedOnDockingPath = true;
		}
	}
}




void ShipManager::moveShipToDock(Level& level, Ship& ship, int direction)
{
	ship.setX(ship.getX() + direction);

	if (level.grid[ship.getX() / level.getCellSize()][ship.getY() / level.getCellSize()]->isVerticalAirlock)
	{
		ship.setX(ship.getX());
		ship.isDocked = true;
	}
}
