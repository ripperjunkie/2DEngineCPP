#include "SpawnerComponent.h"
#include "Engine/GameFramework/Entity.h"



SpawnerComponent::SpawnerComponent(std::shared_ptr<Entity> owner, std::shared_ptr<Entity> objectToSpawn):Component(owner)
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
	std::shared_ptr<Entity> newSpawn;
	
}
