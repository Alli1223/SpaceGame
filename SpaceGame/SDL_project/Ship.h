#pragma once
#include "Texture.h"
class Ship
{
public:
	Ship();
	~Ship();

	int getX() { return x; }
	int getY() { return y; }

	int setX(int newX) { return x = newX; }
	int setY(int newY) { return y = newY; }

	int getWidth() { return width; }
	int getHeight() { return height; }

	int setWidth(int newWidth) { return width = newWidth; }
	int setHeight(int newHeight) { return height = newHeight; }

	std::string getShipStatus() { return shipStatus; }
	std::string setShipStatus(std::string newShipStatus) { return shipStatus = newShipStatus; }

	bool shipPlacedOnDockingPath = false;

	bool isDocked = false;

	void RenderShip(SDL_Renderer* renderer, Ship& ship);

	Texture CargoShipTexture;

private:
	int x, y;
	int width = 200, height = 100;
	std::string shipStatus = "NA";
};

