#pragma once

enum class EStateTypes
{
	Default,
	Red, 
	Yellow,
	Green
};


class State
{
public:
	State(EStateTypes inType) : mStateType(inType)
	{

	}
	void EnterState();
	void RunningState();
	void EndState();

	EStateTypes GetState() const 
	{
		return mStateType;
	}
private: 
	EStateTypes mStateType;
};

inline void State::EnterState()
{
}

inline void State::RunningState()
{
}

inline void State::EndState()
{
}
