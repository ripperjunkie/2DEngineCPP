#pragma once

#include "CoreMinimal.h"
#include "Engine/Public/EngineInterface.h"

#define RENDER_ENGINE RenderingEngine::GetInstance()

class RenderingComponent;

class RenderingEngine
{
public:

	static RenderingEngine* GetInstance()
	{
		if (!sInstance)
		{
			sInstance = new RenderingEngine();
		}
		return sInstance;
	}

	void Render(exEngineInterface* mEngine);
	void AddRenderingComponent(std::shared_ptr<RenderingComponent> componentToAdd);

private:

	RenderingEngine();

	std::vector<std::weak_ptr<RenderingComponent>> mRenderComponents;
	static RenderingEngine* sInstance;
};


