// SDLGame.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "SDL.h"
#include "Game.h"
#include "GameObjects/Components/Time.h"
#include "GameObjects/Components/Settings/Settings.h"

Game* game = 0;

int main(int argc, char* argv[])
{
	// new game instance
	game = new Game();

	//Set up static classes
	Time::Init(60.0f, SDL_GetTicks());
	PhysicSettings::Init();

	// initialise the game
	game->Init(GameSettings::GetTitle().c_str(), 100, 100, GameSettings::window_width, GameSettings::window_height, GameSettings::GetWindowFlags());

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

