#pragma once

#include "Components/SpriteAnimator.h"

class FryingPan : public SpriteAnimator
{
public:
	FryingPan(SpriteSheet* sprite);
	~FryingPan();

	void Update(float inputValue);

};
