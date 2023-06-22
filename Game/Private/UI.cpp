#include "UI.h"
#include "Engine/Components/Rendering/TextRenderComponent.h"

// player include
#include "Game/Components/HealthComponent.h"
#include "Game/Components/ScoreComponent.h"
#include "Game/Private/Player.h"


UI::UI(FTransform transform) : GameObject(transform)
{
	//mHealthCtr = playerHealth;
	//mScoreCtr = playerScore;
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
	auto health = playerRef->FindComponentByType<HealthComponent>();
	auto score = playerRef->FindComponentByType<ScoreComponent>();

	auto healthText = health->GetCurrentHealth();
	auto scoreText = score->GetCurrentScore();



	if (health->GetCurrentHealth() > 0)
	{
		mTextRenderComponent->SetText("LIVES : " + std::to_string(healthText) + "    SCORE: " + std::to_string(scoreText));
	}
	else
	{
		mTextRenderComponent->SetText("GAME OVER");
	}

	// debug trick
	//int assert = text->GetCurrentHealth();


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
