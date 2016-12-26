#pragma once
#include "Level.h"
#include "Character.h"
#include "Oxygen.h"
class ItemController
{
public:
	ItemController();
	~ItemController();

	void ItemController::Interaction(Level& grid, Character& character, Oxygen& oxygen);

	//!Get door status
	bool getDoorStatus() { return doorStatus; }

	//!Set door status
	bool setDoorStatus(bool newDoorStatus) { return doorStatus = newDoorStatus; }

private:
	//!Door status - True is open - False is closed
	bool doorStatus = false;
	int FireExtinguisherEffectiveness = 10;
};

