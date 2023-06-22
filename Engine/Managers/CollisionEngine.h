#pragma once

#include "CoreMinimal.h"
#include "Engine/Public/EngineInterface.h"

#define COLLISION_ENGINE CollisionEngine::GetInstance()

class CollisionComponent;

class CollisionEngine
{
public:
	static CollisionEngine* GetInstance()
	{
		if (!sInstance)
		{
			sInstance = new CollisionEngine();
		}
		return sInstance;
	}

	void UpdateCollision();
	void AddCollisionComponent(std::shared_ptr<CollisionComponent> componentToAdd);

private:

	CollisionEngine();
	std::vector<std::shared_ptr<CollisionComponent>> mCollisionComponents;
	static CollisionEngine* sInstance;
};

