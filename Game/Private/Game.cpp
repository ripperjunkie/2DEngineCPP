#include "Game/Private/Game.h"

// Managers
#include "Engine/Managers/RenderingEngine.h"
#include "Engine/Managers/EntityManager.h"
#include "Engine/Managers/PhysicsEngine.h"
#include "Engine/Managers/CollisionEngine.h"

// Game objects
#include "Food.h"
#include "Player.h"
#include "Enemy.h"
#include "UI.h"


#include "Engine/Managers/Random.h"
#include "Engine/Managers/World.h"

const char* gWindowName = "Sample Epicenter Game Engine";


#define ENEMIES_AMOUNT 5
#define FOOD_AMOUNT 5

#define DEFAULT_FONT "Resources/04B_21.ttf"
#define FONT_SIZE 32 


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
	mFontID = mEngine->LoadFont(DEFAULT_FONT, FONT_SIZE);

	FTransform transform = FTransform{ { kViewportWidth / 2, kViewportHeight / 2},{250.f,250.f },{250.f,250.f } };

	// Spawning player 
	PlayerRef = ENTITY_MANAGER->SpawnEntity<Player>(transform);

	// Spawning enemies
	for (int i = 0; i < ENEMIES_AMOUNT; ++i)
	{
		int x = Random<int>::RandomRange(0, kViewportWidth);
		int y = Random<int>::RandomRange(0, kViewportHeight);
		float _x = (float)x;
		float _y = (float)y;

		FTransform transform = FTransform{ { _x, _y},{100.0f, 100.0f },{200.0f, 200.0f} };

		std::shared_ptr<Enemy> gameObject = ENTITY_MANAGER->SpawnEntity<Enemy>(transform);
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

		std::shared_ptr<Food> gameObject = ENTITY_MANAGER->SpawnEntity<Food>(transform);
		gameObject->RandomizeVelocity();
	}

	// Spawning ui
	FTransform HUDTransform = FTransform{ { 0.f, 0.f},{250.f,250.f },{250.f,250.f } };
	std::shared_ptr<UI> Hud = ENTITY_MANAGER->SpawnEntity<UI>(HUDTransform);

	if (Hud)
	{
		Hud->playerRef = PlayerRef;
	}

	// Call WorldEnter function in every entity.
	ENTITY_MANAGER->Initialize();
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
	std::thread renderThread(&RenderingEngine::Render, RenderingEngine::GetInstance(), mEngine);
	std::thread physicsThread(&PhysicsEngine::UpdatePhysics, PhysicsEngine::GetInstance());
	std::thread collisionThread(&CollisionEngine::UpdateCollision, CollisionEngine::GetInstance());

	renderThread.join();
	physicsThread.join();
	collisionThread.join();

	ENTITY_MANAGER->Update();
	WORLD->dt = fDeltaT;

}
 