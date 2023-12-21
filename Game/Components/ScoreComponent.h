#pragma once
#include "CoreMinimal.h"
#include "Engine/Components/Component.h"


class Entity;

class ScoreComponent:public Component
{
public:

	ScoreComponent() = delete;
	ScoreComponent(std::shared_ptr<Entity> owner);


	virtual EComponentTypes GetComponentType() const override;

	virtual void BeginPlay() override;
	virtual void EndPlay() override;
	virtual void Tick() override;

	void AddScore(int scoreToAdd);
	void SetScore(int scoreToSet);
	int GetCurrentScore();

	int mCurrScore;
};

