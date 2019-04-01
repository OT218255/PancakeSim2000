#pragma once
#include <String>
#include "SDL.h"			// i dont why but the forwards declaration for SDL_Texture is not work, buts its fine if i include SDL.h, hmmmm.

class SDL_Surface;
class SDL_PixelFormat;
class SDL_Texture;
class SDL_Renderer;

// Loads and optimizes an image for SDL
class Sprite
{
public:
	Sprite();
	~Sprite();

	void SetSprite(SDL_Renderer* renderer, std::string path);
	virtual SDL_Texture* GetSprite();
	
protected:

	SDL_Texture* spriteTexture;

};
