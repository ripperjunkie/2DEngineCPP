#pragma once

#include "CoreMinimal.h"
#include "Engine/GameFramework/Entity.h"

#include <type_traits>

#define ENTITY_MANAGER EntityManager::GetInstance()


class EntityManager : public std::enable_shared_from_this<Entity>
{
public:
	static EntityManager* GetInstance()
	{
		// Check if it's nullptr
		if (!sInstance)
		{
			sInstance = new EntityManager();
		}

		return sInstance;
	}
	void Initialize();
	void Update();

	// handle game object spawning, register to game object list 
	template<std::derived_from<Entity> T, typename... Args>
	std::shared_ptr<T> SpawnEntity(Args... arguments)
	{
		std::shared_ptr<T> newEntity = std::make_shared<T>(arguments...);
		mGameObjectList.push_back(newEntity);
		newEntity->WorldEnter();
		return newEntity;
	}


	void DestroyEntity(Entity* entity);


private:
	std::vector<std::shared_ptr<Entity>> mGameObjectList;
	static EntityManager* sInstance;


	// prevent from other classes to create an instance of this class
	EntityManager();
};
