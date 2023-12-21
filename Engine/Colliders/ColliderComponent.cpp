#include "ColliderComponent.h"
#include "Engine/Managers/CollisionEngine.h"

CollisionComponent::CollisionComponent(std::shared_ptr<Entity> owner) : Component(owner)
{

}

void CollisionComponent::BeginPlay()
{
	if (mOwner)
	{
		COLLISION_ENGINE->AddCollisionComponent(shared_from_this());
	}

	// lambda binding
	collisionDelegate = [this](std::shared_ptr<Entity> otherActor)
	{
		OnCollisionOverlap(otherActor);
	};

	ListenToCollision(collisionDelegate);
}

void CollisionComponent::Tick()
{

}

void CollisionComponent::EndPlay()
{
	StopListenToCollision(collisionDelegate);
}

EComponentTypes CollisionComponent::GetComponentType() const
{
	return EComponentTypes::Shape;
}


void CollisionComponent::ListenToCollision(CollisionEventSignature delegateToAdd)
{
	mCollisionEvents.push_back(delegateToAdd);
	//LOG("listen to collision");
}

void CollisionComponent::StopListenToCollision(CollisionEventSignature delegateToRemove)
{
	// using erase function from the algorithm library to easy way to remove element from std::vector
	//std::erase(mCollisionEvents, delegateToRemove);
}

void CollisionComponent::OnCollisionOverlap(std::shared_ptr<Entity> otherActor)
{
	
	if (otherActor)
	{
		// TODO:
		//if (std::shared_ptr<RenderingComponent> ourActor = mOwner->FindComponentByType<RenderingComponent>())
		//{
		//	ourActor->SetColor(exColor{ 0,0,0,255 }); //  
		//}
	//	LOG("Other actor: " << &otherActor);
		return;
	}
//	LOG("Invalid actor");
}


