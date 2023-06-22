#include "Game/Private/Game.h"

// Managers
#include "Engine/Managers/RenderingEngine.h"
#include "Engine/Managers/GameObjectManager.h"
#include "Engine/Managers/PhysicsEngine.h"
#include "Engine/Managers/CollisionEngine.h"

// Game objects
#include "Food.h"
#include "Player.h"
#include "Enemy.h"
#include "UI.h"


#include "Engine/Managers/Random.h"
#include "Engine/Managers/World.h"

const char* gWindowName = "Sample EngineX Game";


#define ENEMIES_AMOUNT 5
#define FOOD_AMOUNT 5


MyGame::MyGame()
	: mEngine( nullptr )
	, mFontID( -1 )
	, mUp( false )
	, mDown( false )
{
}


MyGame::~MyGame()
{
}


void MyGame::Initialize( exEngineInterface* pEngine )
{
	mEngine = pEngine;
	mFontID = mEngine->LoadFont("Resources/04B_21.ttf", 32);

	FTransform transform = FTransform{ { kViewportWidth / 2, kViewportHeight / 2},{250.f,250.f },{250.f,250.f } };

	// Spawning player 
	PlayerRef = GAME_OBJECT_ENGINE->SpawnGameObject<Player>(transform);

	// Spawning enemies
	for (int i = 0; i < ENEMIES_AMOUNT; ++i)
	{
		int x = Random<int>::RandomRange(0, kViewportWidth);
		int y = Random<int>::RandomRange(0, kViewportHeight);
		float _x = (float)x;
		float _y = (float)y;

		FTransform transform = FTransform{ { _x, _y},{100.0f, 100.0f },{200.0f, 200.0f} };

		std::shared_ptr<Enemy> gameObject = GAME_OBJECT_ENGINE->SpawnGameObject<Enemy>(transform);
		gameObject->RandomizeVelocity();
	}


	// Spawning food
	for (int i = 0; i < FOOD_AMOUNT; ++i)
	{
		int x = Random<int>::RandomRange(0, kViewportWidth);
		int y = Random<int>::RandomRange(0, kViewportHeight);
		float _x = (float)x;
		float _y = (float)y;

		FTransform transform = FTransform{ { _x, _y},{100.0f, 100.0f },{20.0f, 20.0f} };

		std::shared_ptr<Food> gameObject = GAME_OBJECT_ENGINE->SpawnGameObject<Food>(transform);
		gameObject->RandomizeVelocity();
	}

	// Spawning ui
	FTransform HUDTransform = FTransform{ { 0.f, 0.f},{250.f,250.f },{250.f,250.f } };
	std::shared_ptr<UI> Hud = GAME_OBJECT_ENGINE->SpawnGameObject<UI>(HUDTransform);

	if (Hud)
	{
		Hud->playerRef = PlayerRef;
	}


	GAME_OBJECT_ENGINE->Initialize();
}


const char* MyGame::GetWindowName() const
{
	return gWindowName;
}


void MyGame::GetClearColor( exColor& color ) const
{
	color.mColor[0] = 0;
	color.mColor[1] = 0;
	color.mColor[2] = 0;
}


void MyGame::OnEvent( SDL_Event* pEvent )
{

}


void MyGame::OnEventsConsumed()
{
	int nKeys = 0;	
	PlayerRef->pState = SDL_GetKeyboardState(&nKeys);
}


void MyGame::Run( float fDeltaT )
{
	//int y = 0;
	//int x = 0;
	//SDL_GetMouseState(&x, &y); // Get mouse position x, y	



	std::thread renderThread(&RenderingEngine::Render, RenderingEngine::GetInstance(), mEngine);
	std::thread physicsThread(&PhysicsEngine::UpdatePhysics, PhysicsEngine::GetInstance());
	std::thread collisionThread(&CollisionEngine::UpdateCollision, CollisionEngine::GetInstance());

	renderThread.join();
	physicsThread.join();
	collisionThread.join();

	GAME_OBJECT_ENGINE->Update();
	WORLD->dt = fDeltaT;

}
 