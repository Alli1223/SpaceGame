#include "stdafx.h"
#include "Hydroponics.h"


Hydroponics::Hydroponics() :hydroponicsTexture("Resources\\FireExtinguisher.png")
{
	
}


Hydroponics::~Hydroponics()
{
}

void Hydroponics::spawnItem(SDL_Renderer* renderer, int x, int y)
{
	hydroponicsTexture.render(renderer, x, y, getwidth() * 2, getheight());
}
