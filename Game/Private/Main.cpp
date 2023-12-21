//
// * ENGINE-X
// * SAMPLE GAME
//
// + Main.cpp
// entry point
//

#include "Game/Private/Game.h"
#include "Engine/Public/EngineInterface.h"

#include <windows.h>
#include <string> 
#include <exception>
//------------------------------------------------------------------
//-----------------------------------------------------------------


//-----------------------------------------------------------------
//-----------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// this is could be better, think design patterns as to why
	MyGame* gGame = new MyGame();

	// Create a new console window in case if you wish to debug data.
	AllocConsole();

	// Attach the console to the application
	AttachConsole(ATTACH_PARENT_PROCESS);

	// Get the console output handle
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Redirect the standard output stream to the console
	FILE* file = nullptr;
	freopen_s(&file, "CONOUT$", "w", stdout);


	// never allow two instances
	if (hPrevInstance)
	{
		return 0;
	}

	// check version
	if (AccessEngineVersion() != kEngineVersion)
	{
		std::cout << "Incompatible engine version";
		system("PAUSE>0");
		return ERROR;
	}

	SDL_Window* window;
	SDL_Renderer* renderer;

	
	// Assuming you want a window of width 800, height 600, and default flags:
	Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL; // Example flags

	if (SDL_CreateWindowAndRenderer(800, 600, flags, &window, &renderer) == 0)
	{
		// Window and renderer created successfully, you can now use 'window' and 'renderer'
		std::cout << "Window and renderer created successfully" << std::endl;
	}
	else
	{
		// Error handling if window or renderer creation failed
		std::cerr << "Failed creating window or renderer" << std::endl;
	}


	// find the engine
	exEngineInterface* pEngine = AccessEngine();

	if (!pEngine)
	{
		std::cout << "Couldn't find engine version " << kEngineVersion;
		system("PAUSE>0");
		return ERROR;
	}


	// tell it to run
	pEngine->Run(&*gGame);	// Close the console and detach it from the application

	
	// Detach console from receiving input and sending outputs
	FreeConsole();

	delete gGame;

	return 0;
}
