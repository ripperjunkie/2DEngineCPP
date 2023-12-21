#include "Food.h"

// Engine 
#include "Engine/Colliders/BoxColliderComponent.h"
#include "Engine/Components/Rendering/BoxRenderComponent.h"
#include "Engine/Components/PhysicsComponent.h"
#include "Engine/Managers/Random.h"


Food::Food(FTransform transform) : Entity(transform)
{
}


void Food::WorldEnter()
{
	Entity::WorldEnter();

	if (!mCircleRenderComp)
	{
		mCircleRenderComp = AddComponent<BoxRenderComponent>(transform.scale.x, transform.scale.y);
	}

	if (!mCircleColliderComp)
	{
		mCircleColliderComp = AddComponent<BoxColliderComponent>(transform.scale.x, transform.scale.y);
	}

	if (!mPhysComp)
	{
		mPhysComp = AddComponent<PhysicsComponent>();
	}

	if (mCircleRenderComp)
	{
		mCircleRenderComp->SetColor(BLUE);
	}
}

void Food::Tick()
{
	Entity::Tick();

	exVector2 currPosition = mTransformComp->GetPosition();


	if (currPosition.y > kViewportHeight || currPosition.x > kViewportWidth
		|| currPosition.x < 0 || currPosition.y < 0)
	{
		ResetPosition();
	}

}

void Food::WorldExit()
{
	Entity::WorldExit();

}

void Food::RandomizeVelocity()
{
	/*
	* Here we simply randomize the object velocity, should it move horizontally or vertically...
	* It should only move in one axis at a time
	*/
	if (!mPhysComp)
		return;

	int horizontalMov = Random<int>::RandomRange(1, 2);
	if (horizontalMov == 1)
	{
		mPhysComp->SetVelocity
		(
		{	Random<int>::RandomRange(0, 2) == 1 ? 1.f : -1.f, 0 }
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

void Food::ResetPosition()
{
	float randX = float(Random<int>::RandomRange(0, kViewportWidth));
	float randY = float(Random<int>::RandomRange(0, kViewportHeight));

	mTransformComp->SetPosition(exVector2{ randX,randY });
}
