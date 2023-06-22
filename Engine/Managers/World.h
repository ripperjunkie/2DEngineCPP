#pragma once

#include "CoreMinimal.h"
#include "Engine/Public/EngineInterface.h"


#define WORLD World::GetInstance()


class World
{
	friend class MyGame;
public:
	inline static World* GetInstance()
	{
		if (!sInstance)
		{
			sInstance = new World();
		}
		return sInstance;
	}

	inline static float DeltaTimeSeconds()
	{
		return dt;
	}



private:

	World()
	{

	}

	static World* sInstance;
	static float dt;

};


