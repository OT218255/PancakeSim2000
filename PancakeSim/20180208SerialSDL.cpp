// 20180208SerialSDL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SDL.h"
#include "Game.h"


Game* game = 0;


int main(int argc, char* argv[])
{
	// new game instance
	game = new Game();

	// initialise the game
	game->Init("PancakeSim2000", 100, 100, 640, 480, 0);

	// create a game loop
	while (game->Running()) {

		// 1000 % 16 which is ~62FPS
		int increment = SDL_GetTicks() % 16;

		// if modulo returns 0 trigger one frame in our game
		if (increment == 0) {

			game->HandleEvents();			// Keyboard events
			game->HandleSerialEvents();		// Serial Events
			game->Update();					// Main Update
			game->Render();					// Render to screen

		}
	}

	// when the game ends clean SDL and Serial
	game->Clean();

    return 0;
}

