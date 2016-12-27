#pragma once
#include "Texture.h"
//! 
/*!

*/
class Cell
{
public:
	//! A constructor
	Cell();
	//! An alternate constructor
	/*!
	This constructor requires an X and Y for the Cell 
	*/
	Cell(int x, int y);
	//! A destructor 
	~Cell();

	// Getter functions
	//! Gets the Cell's X value
	int getX() const { return x; }
	//! Gets the Cell's Y value
	int getY() const { return y; }
	//! Gets the Cell's oxygenLevel
	int getOxygenLevel() { return oxygenLevel; }
	
	// Setter functions
	//! Sets the Cells X value
	int setX(int newX) { return x = newX; }
	//! Sets the Cells Y value
	int setY(int newY) { return y = newY; }
	//! Sets the Cell's oxygenLevel
	int setOxygenLevel(int newOxygenLevel) { return oxygenLevel = newOxygenLevel; }

	//! Whether the cell is part of a roomm
	bool isRoom = false;
	//! Whether the cell is a door is open
	bool isOpenDoor = false;
	//! Whether the cell door is closed
	bool isClosedDoor = false;
	//! Represents the goal for the player
	bool isGoal = false;
	//! The oxygenLevel of the cell
	int oxygenLevel = 100;
	//! Whether the cell is on fire
	bool isOnFire = false;
	//! Whether the cell is a hull breach
	bool isHullBreach = false;
	//! Whether the cell is an oxygen tank
	bool isOxygenTank = false;
	//! Whether the cell is an Fire extengusher
	bool isHealthPack = false;
	//! Whether the cell is a vacuum
	bool isVacuum = false;
	//!Whether the cell is the dockingpath
	bool isDockingPath = false;

	//! cell Orientation
	int cellOrientation = 9;

private:
	//! The Cells X and Y values
	int x = 0, y = 0;
};