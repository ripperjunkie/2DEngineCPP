#pragma once

#include "Engine/GameFramework/GameObject.h"
#include "3rdParty/SDL/SDL2-2.0.3/include/SDL_scancode.h"


#include "Engine/Colliders/ColliderComponent.h"

class PhysicsComponent;
class CircleRenderComponent;
class CircleColliderComponent;
class ScoreComponent;
class HealthComponent;

class Player : public GameObject
{
public:
	Player(FTransform transform);
	virtual void BeginPlay();
	virtual void Tick();
	virtual void EndPlay();

	void Movement();
	void ScreenBounds();

	exVector2 initPosition;

	/* Components */
	std::shared_ptr<CircleRenderComponent> mCircleRenderComp;
	std::shared_ptr<CircleColliderComponent> mCircleColliderComp;
	std::shared_ptr<PhysicsComponent> mPhysComp;
	std::shared_ptr<HealthComponent> mHealthComp;
	std::shared_ptr<ScoreComponent> mScoreComp;

	// Collision related
	CollisionEventSignature collisionDelegate;
	void OnCollisionOverlap(std::shared_ptr<GameObject> otherActor);


public:
	const unsigned char* pState;
	float movSpeed;
	exVector2 direction;

private:

};