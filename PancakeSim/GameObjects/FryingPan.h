#pragma once

#include "Components/SpriteAnimator.h"

class Vector2;

class FryingPan : public SpriteAnimator
{
public:
	FryingPan(SpriteSheet* sprite);
	~FryingPan();

	void Begin();
	void Update(float inputValue, float hobValue);

	int GetCurrentSpriteId();

private:
	int currentSpriteID = 0;
	FVector2* startPosition;
};

