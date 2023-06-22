//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.h
// definition of MyGame, an implementation of exGameInterface
//

#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"

#include "CoreMinimal.h"



// Forward declaration
class GameObject;
class Ball;
class Player;
class Enemy;
class Food;
class UI;

//-----------------------------------------------------------------
//-----------------------------------------------------------------

class MyGame : public exGameInterface
{
public:

	MyGame();
	virtual						~MyGame();

	virtual void				Initialize(exEngineInterface* pEngine);

	virtual const char* GetWindowName() const;
	virtual void				GetClearColor(exColor& color) const;

	virtual void				OnEvent(SDL_Event* pEvent);
	virtual void				OnEventsConsumed();

	virtual void				Run(float fDeltaT);

	float timer;

	bool hasMoved = false;

private:

	exEngineInterface* mEngine;

	int							mFontID;

	bool						mUp;
	bool						mDown;

	exVector2					mTextPosition;

	std::shared_ptr <Player > PlayerRef;





};
