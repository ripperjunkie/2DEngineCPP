#include "PhysicsComponent.h"

#include "Engine/Components/Transform.h"
#include "Engine/GameFramework/Entity.h"
#include "Engine/Managers/PhysicsEngine.h"

#include <algorithm>
#include <memory>

PhysicsComponent::PhysicsComponent(std::shared_ptr<Entity> owner, exVector2 velocity)
	: Component(owner)
{

}

void PhysicsComponent::BeginPlay()
{
	if (mOwner)
	{
		PHYSICS_ENGINE->AddPhysicsComponent(shared_from_this());
	}
}

void PhysicsComponent::EndPlay()
{
}

void PhysicsComponent::Tick()
{

}

EComponentTypes PhysicsComponent::GetComponentType() const
{
	return EComponentTypes::Physics;
}

void PhysicsComponent::ComputePhysics()
{
	if (std::shared_ptr<Transform> transformComp = mOwner->FindComponentByType<Transform>())
	{
		transformComp->SetPosition(transformComp->GetPosition() + mVelocity);
	}
}

void PhysicsComponent::SetVelocity(exVector2&& newVelocity)
{
	mVelocity = newVelocity;
}



void PhysicsComponent::AddVelocity(exVector2&& velocity)
{
	mVelocity.x = mVelocity.x + velocity.x;
	mVelocity.y = mVelocity.y + velocity.y;
}

exVector2 PhysicsComponent::GetVelocity() const
{
	return mVelocity;
}
