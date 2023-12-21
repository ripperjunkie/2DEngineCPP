#pragma once
#include "Engine/GameFramework/Entity.h"

class PhysicsComponent;
class BoxRenderComponent;
class BoxColliderComponent;

class Food : public Entity
{

public:

	Food(FTransform transform);

	virtual void WorldEnter();
	virtual void Tick();
	virtual void WorldExit();
	void RandomizeVelocity();
	void ResetPosition();

	std::shared_ptr<BoxRenderComponent> mCircleRenderComp;
	std::shared_ptr<BoxColliderComponent> mCircleColliderComp;
	std::shared_ptr<PhysicsComponent> mPhysComp;
};

