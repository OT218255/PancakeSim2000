// SDLGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SDL.h"
#include "Game.h"
#include "GameObjects/Components/Time.h"

Game* game = 0;

int main(int argc, char* argv[])
{
	// new game instance
	game = new Game();

	//Set up static classes
	Time::Setup(60.0f, SDL_GetTicks());

	// initialise the game
	game->Init("PancakeSim2000", 100, 100, 640, 480, 0);


	// create a game loop
	while (game->Running()) {

		// Trigger a frame in sync with the target fps in time
		if ( Time::Update( SDL_GetTicks() ) ) {

			game->HandleEvents();			// Handle both keyboard and serial events
			game->Update();					// Main Update
			game->Render();					// Render to screen

		}
	}

	// when the game ends clean SDL and Serial
	game->Clean();

    return 0;
}

