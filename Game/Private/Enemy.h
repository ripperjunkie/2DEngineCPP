#pragma once

#include "Engine/GameFramework/Entity.h"

class PhysicsComponent;
class CircleRenderComponent;
class CircleColliderComponent;


class Enemy : public Entity
{

public:
	
	
	Enemy(FTransform transform);


	virtual void WorldEnter();
	virtual void Tick();
	virtual void WorldExit();
	void RandomizeVelocity();
	void ResetPosition();
	
	std::shared_ptr<CircleRenderComponent> mCircleRenderComp;
	std::shared_ptr<CircleColliderComponent> mCircleColliderComp;
	std::shared_ptr<PhysicsComponent> mPhysComp;

	exVector2 initPosition;
	exVector2 initVelocity;
};

