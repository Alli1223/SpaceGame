#include "stdafx.h"
#include "Items.h"


Items::Items() :hydroponicsTexture("Resources\\FireExtinguisher.png")
{
}


Items::~Items()
{
}

void Items::renderItems(SDL_Renderer* renderer)
{
	for (int iter = 0; iter < allHydroponicsFarms.size(); iter++)
	{
		if (allHydroponicsFarms.size() > 1)
		{
			hydroponicsTexture.render(renderer, allHydroponicsFarms[iter].getX() / 25, allHydroponicsFarms[iter].getY() / 25, allHydroponicsFarms[iter].getwidth(), allHydroponicsFarms[iter].getheight());

		}
		hydroponicsTexture.render(renderer, allHydroponicsFarms[iter].getX() / 25, allHydroponicsFarms[iter].getY() / 25, allHydroponicsFarms[iter].getwidth(), allHydroponicsFarms[iter].getheight());
	}
}