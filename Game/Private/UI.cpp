#include "UI.h"
#include "Engine/Components/Rendering/TextRenderComponent.h"

// player include
#include "Game/Components/HealthComponent.h"
#include "Game/Components/ScoreComponent.h"
#include "Game/Private/Player.h"


UI::UI(FTransform transform) : Entity(transform)
{
}

UI::~UI()
{
}

void UI::WorldEnter()
{
	if (!mTextRenderComponent)
	{
		mTextRenderComponent = AddComponent<TextRenderComponent>();
	}

	if (playerRef)
	{
		health = playerRef->FindComponentByType<HealthComponent>();
		score = playerRef->FindComponentByType<ScoreComponent>();
	}

	Entity::WorldEnter();
}

void UI::Tick()
{
	Entity::Tick();

	UpdateUI();
}

void UI::WorldExit()
{
}

void UI::UpdateUI()
{
	if (!health)
	{
		health = playerRef->FindComponentByType<HealthComponent>();
		return;
	}

	if (!score)
	{
		score = playerRef->FindComponentByType<ScoreComponent>();
		return;
	}

	int healthText = health->GetCurrentHealth();
	int scoreText = score->GetCurrentScore();

	if (health->GetCurrentHealth() > 0)
	{
		mTextRenderComponent->SetText("LIVES : " + std::to_string(healthText) + "    SCORE: " + std::to_string(scoreText));
	}
	else
	{
		mTextRenderComponent->SetText("GAME OVER");
	}
}

