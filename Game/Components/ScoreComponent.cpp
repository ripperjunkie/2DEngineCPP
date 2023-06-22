#include "ScoreComponent.h"




ScoreComponent::ScoreComponent(std::shared_ptr<GameObject> owner): Component(owner)
{
	mCurrScore = 0;
}

EComponentTypes ScoreComponent::GetComponentType() const
{
	return EComponentTypes();
}

void ScoreComponent::BeginPlay()
{
}

void ScoreComponent::EndPlay()
{
}

void ScoreComponent::Tick()
{
}

void ScoreComponent::AddScore(int scoreToAdd)
{
	mCurrScore += scoreToAdd;
}

void ScoreComponent::SetScore(int scoreToSet)
{
	mCurrScore = scoreToSet;
}

int ScoreComponent::GetCurrentScore()
{
	return mCurrScore;
}
