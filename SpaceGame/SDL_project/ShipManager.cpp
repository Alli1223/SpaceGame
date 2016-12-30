#include "stdafx.h"
#include "ShipManager.h"


ShipManager::ShipManager()
{
}


ShipManager::~ShipManager()
{
}

void ShipManager::shipTimer(Level& level, std::vector<Ship> allShips)
{
	CargoShip shipOne;
	
	
	if (shipAlreadySpawned)
	{
		findShipSpawn(level, shipOne);
		shipAlreadySpawned = true;
	}

	allShips.push_back(shipOne);

}

void ShipManager::renderShip(std::vector<Ship> allships, SDL_Renderer* renderer)
{
	for each(auto ship in allships)
	{
		ship.RenderShip(renderer);
	}
}



void ShipManager::findShipSpawn(Level& level, Ship& ship)
{
	for (int y = 0; y < level.getLevelHeight(); y++)
	{
		if (level.grid[0][y]->isDockingPath)
		{
			ship.setX(0);
			ship.setY(y);
			moveShipToDock(ship, 1);
		}
		if (level.grid[level.getLevelWidth()][y]->isDockingPath)
		{
			ship.setX(level.getLevelWidth());
			ship.setY(y);
			moveShipToDock(ship, -1);
		}
	}
}




void ShipManager::moveShipToDock(Ship& ship, int direction)
{
	if (ship.getShipStatus() == "NA")
	{
		ship.setShipStatus("Docking");
		ship.setX(ship.getX() + direction);
	}
}
