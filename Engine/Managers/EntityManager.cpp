#include "EntityManager.h"
#include "Engine/GameFramework/Entity.h"

EntityManager* EntityManager::sInstance = nullptr;

EntityManager::EntityManager()
{

}

void EntityManager::Initialize()
{
	for (std::shared_ptr<Entity> currentGO : mGameObjectList)
	{
		currentGO->WorldEnter();
	}
}

void EntityManager::Update()
{
	for (std::shared_ptr<Entity> currentGO : mGameObjectList)
	{
		currentGO->Tick();
	}
}

void EntityManager::DestroyEntity(Entity* entity)
{
	// TODO: Simply destroy entity for now
	if (!entity)
	{
		std::cout << __FUNCTION__ << ": invalid entity on destroy request." << std::endl;
		return;
	}

	// TODO: Remove from world
}