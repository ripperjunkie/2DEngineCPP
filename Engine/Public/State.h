#pragma once

#include "CoreMinimal.h"
#include "Engine/Components/ControllerFSM.h"
#include "Engine/Components/Rendering/RenderingComponent.h"

class State
{
public:
	State()
	{
	}

	virtual void EnterState() {};
	virtual void RunningState() {};
	virtual void EndState() {};

	ControllerFSM* mController;
};


#pragma region Traffic Light FSM

class TrafficLightState : public State
{
public:
	TrafficLightState() {}
	virtual void RunningState()
	{
		mTimer += 0.5f;

		// calls end state
		if (mTimer > 100.f)
		{
			// end state
			this->EndState();
		}
	};

protected:
	float mTimer;
};

class GreenLight : public TrafficLightState
{
public:
	GreenLight() {}

	virtual void EnterState() override
	{
		mController->GetRenderingComponent()->SetColor(GREEN);
		mTimer = 0.f;
	}
	virtual void RunningState() override
	{
		mTimer += 0.5f;

		// calls end state
		if (mTimer > 100.f)
		{
			// end state
			this->EndState();
		}


	}
	virtual void EndState() override
	{
		mController->ChangeState(mController->GetStates()[1]);
	}
};

class YellowLight : public TrafficLightState
{
public:

	YellowLight() {}


	virtual void EnterState() override
	{
		mController->GetRenderingComponent()->SetColor(YELLOW);
		mTimer = 0.f;
	}
	virtual void RunningState() override
	{
		// calls end state at some point
		mTimer += 0.5f;

		// calls end state
		if (mTimer > 100.f)
		{
			// end state
			this->EndState();
		}
	}
	virtual void EndState() override
	{
		mController->ChangeState(mController->GetStates()[2]);

	}

};

class RedLight : public TrafficLightState
{
public:

	RedLight() {}

	virtual void EnterState() override
	{
		mController->GetRenderingComponent()->SetColor(RED);
		mTimer = 0.f;
	}
	virtual void RunningState() override
	{
		// calls end state at some point
		mTimer += 0.5f;

		// calls end state
		if (mTimer > 100.f)
		{
			// end state
			this->EndState();
		}


	}
	virtual void EndState() override
	{
		mController->ChangeState(mController->GetStates()[0]);
	}
};
#pragma endregion