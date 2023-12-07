#pragma once
#include "Engine/Components/Rendering/TextRenderComponent.h"
#include "Engine/GameFramework/GameObject.h"
#include <string>



class Player;
class HealthComponent;
class ScoreComponent;

class UI : public GameObject
{
public:

	UI() = delete;
	UI(FTransform transform);
	~UI();

	virtual void BeginPlay();
	virtual void Tick();
	virtual void EndPlay();


	std::shared_ptr<TextRenderComponent> mTextRenderComponent;

	std::shared_ptr<Player> playerRef;
private:
	void UpdateUI();
	std::shared_ptr<HealthComponent> health;
	std::shared_ptr<ScoreComponent> score;

	exVector2 ScorePosition;
	exVector2 HealthPosition;

	int mFontID;
	std::string mHealthCtr;
	std::string mScoreCtr;


};

