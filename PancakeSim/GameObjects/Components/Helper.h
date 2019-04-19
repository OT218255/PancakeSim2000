#pragma once
#include "SDL.h"

class Helper
{
public:
	static int Random()
	{
		int mouseX, mouseY;

		SDL_GetGlobalMouseState(&mouseX, &mouseY);

		if (mouseY == 0) mouseY = 1;

		int seed = abs((mouseX * (mouseX * 0.5f)) / mouseY);

		if (seed == 0) seed = mouseY;

		int r = rand() % seed;
		return r;

	}
};