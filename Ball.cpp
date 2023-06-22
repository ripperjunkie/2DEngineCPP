#include "Ball.h"
#include "Engine/Components/Rendering/CircleRenderComponent.h"
#include "Engine/Components/Transform.h"
#include "Engine/Components/PhysicsComponent.h"

#include "Engine/Colliders/CircleColliderComponent.h"

Ball::Ball(FTransform transform) : GameObject(transform)
{
	//GameObject();

}

void Ball::BeginPlay()
{
	GameObject::BeginPlay();

	exVector2 startPos{ 250.f,250.f };
	float size = 25.f;
	mTransformComp = AddComponent<Transform>(startPos, startPos, startPos);
	mCircleRenderComp = AddComponent<CircleRenderComponent>(size);
	mCircleColliderComp = AddComponent<CircleColliderComponent>(150.f);

	mPhysComp = AddComponent<PhysicsComponent>();
	//mPhysComp->SetVelocity({ -mBallSpeed, 0.0f });
}

void Ball::EndPlay()
{
	GameObject::EndPlay();


}

void Ball::Tick()
{
	GameObject::Tick();


}