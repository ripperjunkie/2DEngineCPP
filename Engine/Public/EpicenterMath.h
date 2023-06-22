#pragma once
#include <math.h>       // Required for: sinf(), cosf(), tan(), atan2f(), sqrtf(), floor(), fminf(), fmaxf(), fabs()
#include "EngineTypes.h"

// normalize vector
exVector2 NormalizeVector(exVector2& v)
{
	// calculate it's length
	float length = sqrt((v.x * v.x) + (v.y * v.y) );

	
	if (length > 0)
	{
		float iLength = 1.f / length;
		v.x = v.x * iLength;
		v.y = v.y * iLength;
	}


	return v;
}