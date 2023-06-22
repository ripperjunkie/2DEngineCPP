#include "GameObjectManager.h"
#include "Engine/GameFramework/GameObject.h"

GameObjectManager* GameObjectManager::sInstance = nullptr;

GameObjectManager::GameObjectManager()
{

}

void GameObjectManager::Initialize()
{
	for (std::shared_ptr<GameObject> currentGO : mGameObjectList)
	{
		currentGO->BeginPlay();
	}
}

void GameObjectManager::Update()
{
	for (std::shared_ptr<GameObject> currentGO : mGameObjectList)
	{
		currentGO->Tick();
	}
}
