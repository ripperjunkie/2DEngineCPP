﻿#pragma once

#include "Engine/GameFramework/Entity.h"
#include "3rdParty/SDL/SDL2-2.0.3/include/SDL_scancode.h"

#include "Engine/Colliders/ColliderComponent.h"

#include <functional>

typedef std::function<void(int Damage)> OnTakeDamageSignature;

class PhysicsComponent;
class CircleRenderComponent;
class CircleColliderComponent;
class ScoreComponent;
class HealthComponent;

class Player : public Entity
{
public:
	Player(FTransform transform);
	virtual void WorldEnter();
	virtual void WorldExit();
	virtual void Tick();

	void Movement();
	void ScreenBounds();

	exVector2 initPosition;

	/* Components */
	std::shared_ptr<CircleRenderComponent> mCircleRenderComp;
	std::shared_ptr<CircleColliderComponent> mCircleColliderComp;
	std::shared_ptr<PhysicsComponent> mPhysComp;
	std::shared_ptr<HealthComponent> mHealthComp;
	std::shared_ptr<ScoreComponent> mScoreComp;

	// Collision related, callback and overlap
	CollisionEventSignature collisionDelegate;
	void OnCollisionOverlap(std::shared_ptr<Entity> otherActor);

	const unsigned char* pState;
	float movSpeed;
	exVector2 direction;

protected:
	OnTakeDamageSignature OnTakeDamageDelegate;
	void OnTakeDamage(int DamageTaken);

private:
	FTransform _initialTransform;

};