#pragma once

#include "CoreMinimal.h"
#include "Engine/Public/EngineInterface.h"

#include<cstdlib>
#include <time.h>

template<class T>
class Random
{
public:

	
	static Random* GetInstance();
	static T RandomRange(T min, T max);


private:

	Random();

	static Random* sInstance;
};

