#pragma once

#include "CoreMinimal.h"
#include "Engine/GameFramework/GameObject.h"

#include <type_traits>

#define GAME_OBJECT_ENGINE GameObjectManager::GetInstance()


class GameObjectManager : public std::enable_shared_from_this<GameObject>
{
public:
	static GameObjectManager* GetInstance()
	{
		// Check if it's nullptr
		if (!sInstance)
		{
			sInstance = new GameObjectManager();
		}

		return sInstance;
	}
	void Initialize();
	void Update();

	// handle game object spawning, register to game object list 
	template<std::derived_from<GameObject> T, typename... Args>
	std::shared_ptr<T> SpawnGameObject(Args... arguments)
	{
		std::shared_ptr<T> newObject = std::make_shared<T>(arguments...);
		mGameObjectList.push_back(newObject);
		newObject->BeginPlay();
		return newObject;
	}
	


private:
	std::vector<std::shared_ptr<GameObject>> mGameObjectList;
	static GameObjectManager* sInstance;


	// prevent from other classes to create an instance of this class
	GameObjectManager();
};
