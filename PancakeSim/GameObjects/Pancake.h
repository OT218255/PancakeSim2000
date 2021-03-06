#pragma once
#include "Components/SpriteAnimator.h"
#include "stdio.h"


class Rigidbody;

enum CookingState {
	None    = 0,
	Mixture = 1,
	Raw     = 2,
	Perfect = 3,
	Burnt   = 4,
	OnFire  = 5
};

class Pancake : public SpriteAnimator
{
public:

	Pancake(SpriteSheet* sprite);
	~Pancake();

	virtual void Begin() override;
	void Update(float force, int panSpriteId, int panRotation, float onHobValue, float flameSize);

	void PourPancake(float rate);
	void SetPancakeSize(float size);

	float GetPancakeSizePercentage();

	CookingState GetCurrentCookingState();
	// this will lock the state of the pancake if called
	void SetCurrentCookingState(CookingState state);

	bool CanPour();

	void ServePancake(bool hit);

	bool IsInPan();

	void SetPanBottom(float position, float spriteOffset);
	void SetBounds(float x_bounds, float y_bounds);

private:
	
	Rigidbody* rigidbody;
	float default_mass = 0.1f;

	float startPosition;

	float GetFlipPercentage();	// Get the flip playback position in %

	float flipLength = 1.5;			//@ fliForce = 1
	float currentFlip = 0;
	
	const float flipForce = 4;
	float currentFlipForce = 0;
	float counterForce = 2.2f;

	const float minFlipForce = 0.05f;// 0.5f;

	int currentSpriteRow = 0;

// Pan bits
	bool inPan = false;

	float panBottomPosition = 455;
	float panBottom_spriteIdOffset = 6.0f;

	FVector2* outOfBounds;

// Pancake size
	float pancakeSize = 0.0f;
	const float maxPancakeSize = 0.75f;
	const float minPancakeSize = 0.2f;
	float pancakeSizeCookMutiplyer = 2.0f;
	bool canPour = true;

// Cooking
	const float cookingLength = 25.0f;		// the perfect cooking leght, in seconds
	float currentCookingTime = 0.0f;

	CookingState currentCookState = CookingState::None;
	void SetCurrentCookingState();
	
	float GetCookStateHappyness();

	// Pancakes cooking states mutiplyers (cookingLength * mutiplyer)
	const float mixtureMutiplyer = 0.15f;		// Unflipable, any time below this the pancake is still considered batter.
	const float rawMutiplyer = 0.65f;			// Unedable, any time below this the pancake is considered raw
	const float burntMutiplyer = 1.25f;			// Burnt, any time affter this the pancake is considered burnt
	const float fireMutiplyer = 1.65f;			// any time above this triggers the fire alarm, call the fire bargade!

	float force_y_accum = 0;
	int force_y_frameCount = 0;	

};

