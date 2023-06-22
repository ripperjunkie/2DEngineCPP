#include "RenderingEngine.h"
#include "Engine/Components/Rendering/RenderingComponent.h"

// This is just telling the linker how to link this sInstance variable
RenderingEngine* RenderingEngine::sInstance = nullptr;

RenderingEngine::RenderingEngine()
{

}

void RenderingEngine::Render(exEngineInterface* mEngine)
{
	for (std::weak_ptr<RenderingComponent> componentToRender : mRenderComponents)
	{
		if (!componentToRender.expired())
		{
			componentToRender.lock()->Render(mEngine);
		}
	}
}

void RenderingEngine::AddRenderingComponent(std::shared_ptr<RenderingComponent> componentToAdd)
{
	mRenderComponents.push_back(componentToAdd);
}
