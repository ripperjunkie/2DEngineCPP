#include "SpawnerComponent.h"
#include "Engine/GameFramework/GameObject.h"



SpawnerComponent::SpawnerComponent(std::shared_ptr<GameObject> owner, std::shared_ptr<GameObject> objectToSpawn):Component(owner)
{
	mObjectToSpawn = objectToSpawn;
}

EComponentTypes SpawnerComponent::GetComponentType() const
{
	return EComponentTypes();
}

void SpawnerComponent::BeginPlay()
{
}

void SpawnerComponent::EndPlay()
{
}

void SpawnerComponent::Tick()
{
}

void SpawnerComponent::SpawnObject()
{
	std::shared_ptr<GameObject> newSpawn;
	
}
