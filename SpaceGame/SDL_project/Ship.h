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


	void RenderShip(SDL_Renderer* renderer, Ship& ship);
	void RenderShip(SDL_Renderer* renderer);

	Texture CargoShipTexture;

private:
	int x, y;
	int width = 100, height = 50;
	std::string shipStatus = "NA";
};

