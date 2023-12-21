#pragma once
#include "CoreMinimal.h"
#include "engine/Managers/Random.h"
#include "Engine/Components/Component.h"


class SpawnerComponent : public Component
{
public:

	SpawnerComponent() = delete;
	SpawnerComponent(std::shared_ptr<Entity> owner, std::shared_ptr<Entity> objectToSpawn);

	virtual EComponentTypes GetComponentType() const override;

	virtual void BeginPlay() override;
	virtual void EndPlay() override;
	virtual void Tick() override;

	void SpawnObject();

	exVector2 newPosition;
	std::shared_ptr<Entity> mObjectToSpawn;
};

