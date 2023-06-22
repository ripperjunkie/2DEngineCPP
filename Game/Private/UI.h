#pragma once
#include "Engine/Components/Rendering/TextRenderComponent.h"
#include "Engine/GameFramework/GameObject.h"
#include <string>



class Player;

class UI : public GameObject
{
public:

	UI() = delete;
	UI(FTransform transform);
	~UI();

	virtual void BeginPlay();
	virtual void Tick();
	virtual void EndPlay();

	void RenderScore(TextRenderComponent textRenderer, int score, exVector2 positionToRender);
	void RenderHealth(TextRenderComponent textRenderer, int score, exVector2 positionToRender);

	std::shared_ptr<TextRenderComponent> mTextRenderComponent;

	std::shared_ptr<Player> playerRef;
private:

	exVector2 ScorePosition;
	exVector2 HealthPosition;

	int mFontID;
	std::string mHealthCtr;
	std::string mScoreCtr;


};

