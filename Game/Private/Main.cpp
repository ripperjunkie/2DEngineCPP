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

//------------------------------------------------------------------
//-----------------------------------------------------------------

// this is could be better, think design patterns as to why
MyGame gGame;

//-----------------------------------------------------------------
//-----------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// Create a new console window
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
		std::printf("Incompatible engine version");
		return 0;
	}

	// find the engine
	exEngineInterface* pEngine = AccessEngine();

	if (pEngine == nullptr)
	{
		std::printf("Couldn't find engine");
		return 0;
	}

	// tell it to run
	pEngine->Run(&gGame);	// Close the console and detach it from the application

	// Detach console from receiving input and sending outputs
	FreeConsole();

	return 0;
}
