#pragma once
#include "Items.h"

class Hydroponics : public Items
{
public:
	Hydroponics();
	~Hydroponics();

	bool isProducingOxygen = true;

	//! Texture for hydroponics
	Texture hydroponicsTexture;

	void spawnItem(SDL_Renderer* renderer, int x, int y);

private:

	int width = 50;
	int height = 100;

};

