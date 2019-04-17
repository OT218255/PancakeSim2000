#pragma once
#include "stdio.h"
#include <array>
#include "..\..\..\Game.h"



class GameManager
{
//Sigleton setup
public:
	
	static GameManager& GetInstance()
	{
		static GameManager instance;

		return instance;
	}

private:
	GameManager() {}
	GameManager(GameManager const&);
	GameManager& operator=(GameManager const&);

public:

	~GameManager() {};

// Main

	void AddFlip();
	int GetTotalFlips();

	void AddScore(int score);
	int GetTotalScore();

	void ClearScore();

	typedef void (Game::* OnScoreChanged_)();
	OnScoreChanged_ onScoreChanged;

	void TriggerOnScoreChanged();

	void SetActiveGame(Game* activeGame);
	Game* GetActiveGame();

private:
	
	int scorePerFlip = 5;

	int totalPancakeFlips = 0;
	int totalScore = 0;

	Game* activeGame;

};

