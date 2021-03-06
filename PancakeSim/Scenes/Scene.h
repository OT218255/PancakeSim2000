#pragma once

class Game;

/* Base Class for scenes */
class Scene
{
public:
	Scene(Game* mainGame);
	~Scene();

	virtual void Init() = 0;
	virtual void Render() = 0;
	virtual void Update() = 0;
	virtual void UpdateUI() = 0;

	bool HasInitalized();

protected:
	Game* game;

	bool initalized = false;

private:

	// block default constructor
	Scene();		
	
};

