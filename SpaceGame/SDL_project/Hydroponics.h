#pragma once
#include "Items.h"

class Hydroponics : public Items
{
public:
	Hydroponics();
	~Hydroponics();

	void Hydroponics::renderItems(SDL_Renderer* renderer, Level& level, std::vector<Hydroponics>& allHydroponicsFarms);

	bool isProducingOxygen = true;
	bool isProducingFood = true;
	bool isHydroponics = true;

	//! Texture for hydroponics
	Texture hydroponicsTexture;

	void spawnItem(SDL_Renderer* renderer, Level& level, std::vector<Hydroponics>& allHydroponicsFarms, int x, int y);
};

