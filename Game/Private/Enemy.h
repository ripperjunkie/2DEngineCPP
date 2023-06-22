#pragma once

#include "Engine/GameFramework/GameObject.h"

class PhysicsComponent;
class CircleRenderComponent;
class CircleColliderComponent;
class ScoreComponent;
class HealthComponent;


class Enemy : public GameObject
{

public:
	
	
	Enemy(FTransform transform);


	virtual void BeginPlay();
	virtual void Tick();
	virtual void EndPlay();
	void RandomizeVelocity();
	void ResetPosition();
	
	std::shared_ptr<CircleRenderComponent> mCircleRenderComp;
	std::shared_ptr<CircleColliderComponent> mCircleColliderComp;
	std::shared_ptr<PhysicsComponent> mPhysComp;
	std::shared_ptr<PhysicsComponent> mEnemyComp;

	exVector2 initPosition;
	exVector2 initVelocity;
};

