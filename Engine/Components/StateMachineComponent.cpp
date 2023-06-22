#include "Engine/Components/StateMachineComponent.h"

#include "Engine/GameFramework/GameObject.h"
#include "Engine/Components/Rendering/RenderingComponent.h"
#include "Engine/Public/EngineTypes.h"

StateMachineComponent::StateMachineComponent(std::shared_ptr<GameObject> owner, EStateTypes entryState) : Component(owner)
{
	// creating states
	mStates.push_back(std::make_shared<State>(EStateTypes::Red));
	mStates.push_back(std::make_shared<State>(EStateTypes::Yellow));
	mStates.push_back(std::make_shared<State>(EStateTypes::Green));

	mCurrentState = GetStateOfType(entryState);
	mCurrentState->EnterState();

	renderComp = mOwner->FindComponentByType<RenderingComponent>();
	mTimer = 0.f;
}

EComponentTypes StateMachineComponent::GetComponentType() const
{
	return EComponentTypes::StateMachine;
}

void StateMachineComponent::BeginPlay()
{


}

void StateMachineComponent::EndPlay()
{
	mStates.clear();
}

void StateMachineComponent::Tick()
{
	if (!mCurrentState)	
		return;
	

	if (!renderComp)
		return;


	switch (mCurrentState->GetState()) {
	
	case EStateTypes::Red:
	{
		mTimer += 0.5f;
		mCurrentState->RunningState();
		renderComp->SetColor(RED);

		if (mTimer > 30)
		{
			mCurrentState->EndState();
			mCurrentState = GetStateOfType(EStateTypes::Green);
			mCurrentState->EnterState();
			mTimer = 0.f;
		}
	}
	break;

	case EStateTypes::Yellow:
	{
		mTimer += 0.5f;
		mCurrentState->RunningState();
		renderComp->SetColor(YELLOW);

		if (mTimer > 30)
		{
			mCurrentState->EndState();
			mCurrentState = GetStateOfType(EStateTypes::Red);
			mCurrentState->EnterState();
			mTimer = 0.f;
		}
	}
	break;

	case EStateTypes::Green:
	{
		mTimer += 0.5f;
		mCurrentState->RunningState();
		renderComp->SetColor(GREEN);

		if (mTimer > 30)
		{
			mCurrentState->EndState();
			mCurrentState = GetStateOfType(EStateTypes::Yellow);
			mCurrentState->EnterState();
			mTimer = 0.f;
		}

	}
	break;

	default:
		break;
	}
}

std::shared_ptr<State> StateMachineComponent::GetStateOfType(const EStateTypes typeToFind)
{
	for (std::shared_ptr<State> itr : mStates)
	{
		if (itr->GetState() == typeToFind)
		{
			return itr;
		}
	}
	return nullptr;
}
