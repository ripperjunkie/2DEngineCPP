#pragma once
#include "Engine/GameFramework/GameObject.h"

class PhysicsComponent;
class BoxRenderComponent;
class BoxColliderComponent;
class ScoreComponent;
class HealthComponent;

class Food : public GameObject
{

public:

	Food(FTransform transform);

	virtual void BeginPlay();
	virtual void Tick();
	virtual void EndPlay();
	void RandomizeVelocity();
	void ResetPosition();

	std::shared_ptr<BoxRenderComponent> mCircleRenderComp;
	std::shared_ptr<BoxColliderComponent> mCircleColliderComp;
	std::shared_ptr<PhysicsComponent> mPhysComp;
};

