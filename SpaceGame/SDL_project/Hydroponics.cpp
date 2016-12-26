#include "stdafx.h"
#include "Hydroponics.h"


Hydroponics::Hydroponics() :hydroponicsTexture("Resources\\FireExtinguisher.png")
{
	
}


Hydroponics::~Hydroponics()
{
}

void Hydroponics::spawnItem(SDL_Renderer* renderer, Level& level, std::vector<Hydroponics>& allHydroponicsFarms, int x, int y)
{
	Hydroponics hydroponics;
	int xPos = x; int yPos = y;
	hydroponicsTexture.render(renderer, xPos, yPos, getwidth(), getheight());
	hydroponics.setX(x);
	hydroponics.setY(y);
	if (isProducingOxygen && getHealth() > 0)
	{
		level.grid[x / level.getCellSize()][y / level.getCellSize()]->oxygenLevel = 100;
	}
	allHydroponicsFarms.push_back(hydroponics);
}

void  Hydroponics::renderItems(SDL_Renderer* renderer, std::vector<Hydroponics>& allHydroponicsFarms)
{
	for (int iter = 0; iter < allHydroponicsFarms.size(); iter++)
	{
		hydroponicsTexture.render(renderer, allHydroponicsFarms[iter].getX(), allHydroponicsFarms[iter].getY(), allHydroponicsFarms[iter].getwidth(), allHydroponicsFarms[iter].getheight());
	}
}
