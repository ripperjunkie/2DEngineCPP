#include "ControllerFSM.h"

#include "Engine/GameFramework/Entity.h"
#include "Engine/Components/Rendering/RenderingComponent.h"
#include "Engine/Public/EngineTypes.h"
#include "Engine/Public/State.h"


//////////////// ControllerFSM /////////////////////////

ControllerFSM::ControllerFSM(std::shared_ptr<Entity> owner) : Component(owner)
{
	renderComp = mOwner->FindComponentByType<RenderingComponent>();
}

EComponentTypes ControllerFSM::GetComponentType() const
{
	return EComponentTypes::StateMachine;
}

void ControllerFSM::AddState(std::shared_ptr<State> state)
{
	mStates.push_back(state);
}

void ControllerFSM::BeginPlay()
{
	for (int i = 0; i < mStates.size(); ++i)
	{
		mStates[i]->mController = this;
	}
	mCurrentState->EnterState();
}

void ControllerFSM::EndPlay()
{
}

void ControllerFSM::Tick()
{
	Component::Tick();

	if (!mCurrentState)
		return;


	if (!renderComp)
		return;

	mCurrentState->RunningState();
}

void ControllerFSM::ChangeState(std::shared_ptr<State> newState)
{
	// update current state (assign to new state)
	mCurrentState = newState;

	// enter state
	mCurrentState->EnterState();

}
