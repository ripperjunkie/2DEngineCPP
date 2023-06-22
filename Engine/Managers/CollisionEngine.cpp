#include "CollisionEngine.h"
#include "Engine/Colliders/ColliderComponent.h"

CollisionEngine::CollisionEngine()
{

}

CollisionEngine* CollisionEngine::sInstance = nullptr;

void CollisionEngine::UpdateCollision()
{
	for (std::shared_ptr<CollisionComponent> firstComponent : mCollisionComponents)
	{
		for (std::shared_ptr<CollisionComponent> secondComponent : mCollisionComponents)
		{
			if (firstComponent->IsCollisionDetected(secondComponent))
			{
				//LOG("Collision happened");
				for (CollisionEventSignature collisionEvent : firstComponent->mCollisionEvents)
				{
					// Delegate call ('invoke')
					if (collisionEvent)
					{
						collisionEvent(secondComponent->GetOwner());
					}
				}
			}
		}
	}
}

void CollisionEngine::AddCollisionComponent(std::shared_ptr<CollisionComponent> componentToAdd)
{
	// check if we are not adding the same component twice
	for (int i = 0; i < mCollisionComponents.size(); ++i)
	{
		if (mCollisionComponents[i] == componentToAdd)
		{
			return;
		}
	}
	mCollisionComponents.push_back(componentToAdd);
}
