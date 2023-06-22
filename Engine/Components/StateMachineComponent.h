#pragma once

#include "Engine/Components/Component.h"
#include "Engine/Public/State.h"

class RenderingComponent;

class StateMachineComponent : public Component
{
public:
	StateMachineComponent() = delete;
	StateMachineComponent(std::shared_ptr<GameObject> owner, EStateTypes entryState);
	virtual EComponentTypes GetComponentType() const;


	virtual void BeginPlay() override;
	virtual void EndPlay() override;
	virtual void Tick() override;

private: 
	std::shared_ptr<RenderingComponent> renderComp;
	std::shared_ptr<State> mCurrentState;
	std::vector<std::shared_ptr<State>> mStates;
	std::shared_ptr<State> GetStateOfType(const EStateTypes typeToFind);
	float mTimer;
};

