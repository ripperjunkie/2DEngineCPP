#include "Enemy.h"

// Engine 
#include "Engine/Colliders/CircleColliderComponent.h"
#include "Engine/Components/Rendering/CircleRenderComponent.h"
#include "Engine/Components/PhysicsComponent.h"
#include "Engine/Managers/Random.h"



Enemy::Enemy(FTransform transform) : Entity(transform)
{
	
}


void Enemy::WorldEnter()
{
	float intialSize = 15.f;

	if (!mCircleRenderComp)
	{
		mCircleRenderComp = AddComponent<CircleRenderComponent>(intialSize);

	}

	if (!mCircleColliderComp)
	{
		mCircleColliderComp = AddComponent<CircleColliderComponent>(intialSize);
	}

	if (!mPhysComp)
	{
		mPhysComp = AddComponent<PhysicsComponent>();
	}

	Entity::WorldEnter();
	mCircleRenderComp->SetColor(RED);
}

void Enemy::Tick()
{
	Entity::Tick();

	exVector2 currPosition = mTransformComp->GetPosition();
	float randX = float(Random<int>::RandomRange(0, kViewportWidth));
	float randY = float(Random<int>::RandomRange(0, kViewportHeight));


	exVector2 currentPos = exVector2
	{
		mTransformComp->GetPosition().x - mCircleColliderComp->GetRadius(),
		mTransformComp->GetPosition().y - mCircleColliderComp->GetRadius()
	};

	// Reset position if it goes out of bounds
	if (currentPos.y > kViewportHeight || currentPos.x > kViewportWidth
		|| currentPos.y + mCircleColliderComp->GetRadius() < -mCircleColliderComp->GetRadius() || currentPos.x + mCircleColliderComp->GetRadius() < -mCircleColliderComp->GetRadius())
	{
		mTransformComp->SetPosition(exVector2{ randX, randY });
	}
}

void Enemy::WorldExit()
{
	Entity::WorldExit();

	
}

void Enemy::RandomizeVelocity()
{
	if (!mPhysComp)
		return;

	/* 
	* Here we simply randomize the object velocity, should it move horizontally or vertically...
	* It should only move in one axis at a time
	*/
	int horizontalMov = Random<int>::RandomRange(1, 2);
	if (horizontalMov == 1)
	{
		mPhysComp->SetVelocity
		(
			{ Random<int>::RandomRange(0, 2) == 1 ? 1.f : -1.f, 0 }
		);
	}
	else
	{
		mPhysComp->SetVelocity
		(
			{ Random<int>::RandomRange(0, 2) == 1 ? 1.f : -1.f, 0 }
		);
	}
}

void Enemy::ResetPosition()
{
	float randX = float(Random<int>::RandomRange(0, kViewportWidth));
	float randY = float(Random<int>::RandomRange(0, kViewportHeight));

	mTransformComp->SetPosition(exVector2{ randX,randY });
}
