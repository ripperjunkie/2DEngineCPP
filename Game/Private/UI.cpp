#include "UI.h"
#include "Engine/Components/Rendering/TextRenderComponent.h"

// player include
#include "Game/Components/HealthComponent.h"
#include "Game/Components/ScoreComponent.h"
#include "Game/Private/Player.h"


UI::UI(FTransform transform) : GameObject(transform)
{
}

UI::~UI()
{
}

void UI::BeginPlay()
{
	if (!mTextRenderComponent)
	{
		mTextRenderComponent = AddComponent<TextRenderComponent>();

	}
	GameObject::BeginPlay();

}

void UI::Tick()
{
	if (!playerRef)
		return;
	std::shared_ptr<HealthComponent> health = playerRef->FindComponentByType<HealthComponent>();
	std::shared_ptr<ScoreComponent> score = playerRef->FindComponentByType<ScoreComponent>();

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

void UI::EndPlay()
{
}

void UI::RenderScore(TextRenderComponent textRenderer, int score, exVector2 positionToRender)
{
	
}

void UI::RenderHealth(TextRenderComponent textRenderer, int score, exVector2 positionToRender)
{
}
