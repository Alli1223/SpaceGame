#pragma once
#include "CargoShip.h"
#include "Level.h"
class ShipManager
{
public:
	//! Constructor
	ShipManager();
	//! Destructor
	~ShipManager();

	//! Spawns a ship and moves it to the dock
	void moveShipToDock(Ship& ship, int direction);

	void shipTimer(Level& level, std::vector<Ship> allShips);
	void findShipSpawn(Level& level, Ship& ship);
	bool shipAlreadySpawned = false;

	void renderShip(std::vector<Ship> allships, SDL_Renderer* renderer);

private:
	
};

