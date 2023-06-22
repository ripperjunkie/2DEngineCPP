#pragma once

#include "Engine/Components/Component.h"

class RenderingComponent;
class State;


// This class will act as a controller for finite state machine
class ControllerFSM : public Component
{
public:
	// Traffic light : state types
	ControllerFSM() = delete;
	ControllerFSM(std::shared_ptr<GameObject> owner);
	virtual EComponentTypes GetComponentType() const;

	void AddState(std::shared_ptr<State> state);
	virtual void BeginPlay() override;
	virtual void EndPlay() override;
	virtual void Tick() override;

	virtual void ChangeState(std::shared_ptr<State> newState);

	std::vector<std::shared_ptr<State>> GetStates() const
	{
		return mStates;
	}
	std::shared_ptr<RenderingComponent> GetRenderingComponent() const
	{
		return renderComp;
	}

protected:
	std::vector<std::shared_ptr<State>> mStates;
	std::shared_ptr<State> mCurrentState;
	std::shared_ptr<RenderingComponent> renderComp;
};





class TrafficLightFSM : public ControllerFSM
{
public:
	TrafficLightFSM(std::shared_ptr<GameObject> owner) : ControllerFSM(owner)
	{

	}


	virtual void BeginPlay() override;

	virtual void EndPlay() override;

	virtual void Tick() override;



};