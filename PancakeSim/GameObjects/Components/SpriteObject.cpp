#include "SpriteObject.h"
#include "Sprite.h"
#include "Vector2.h"
#include "SDL.h"
#include "Time.h"


SpriteObject::SpriteObject(Sprite* spr) : Transform()
{
	sprite = spr;
}


SpriteObject::~SpriteObject()
{
}

void SpriteObject::Begin()
{
	SetSize(sprite->GetSpriteSize()->x, sprite->GetSpriteSize()->y);
}

void SpriteObject::Render(SDL_Renderer* renderer)
{

	// Get the position to render the sprite
	SDL_Rect* destPos = GetRectScaled();

	sprite->RenderSprite(renderer, destPos, GetRotation());

}

Sprite* SpriteObject::GetSprite()
{
	return sprite;
}