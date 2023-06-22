#pragma once
#include "CoreMinimal.h"
#include "Engine/Components/Component.h"


class GameObject;

class ScoreComponent:public Component
{
public:

	ScoreComponent() = delete;
	ScoreComponent(std::shared_ptr<GameObject> owner);


	virtual EComponentTypes GetComponentType() const override;

	virtual void BeginPlay() override;
	virtual void EndPlay() override;
	virtual void Tick() override;

	void AddScore(int scoreToAdd);
	void SetScore(int scoreToSet);
	int GetCurrentScore();

	int mCurrScore;
};

