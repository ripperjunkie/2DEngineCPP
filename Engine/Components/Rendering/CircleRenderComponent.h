#pragma once

#include "RenderingComponent.h"
#include "Engine/Public/EngineInterface.h"

class CircleRenderComponent : public RenderingComponent
{
public:
	CircleRenderComponent(std::shared_ptr<Entity> owner, float mRadius = 1.f, exColor color = {255,0,0,255});

	virtual void Render(exEngineInterface* engineInterface) override;

private:
	float mRadius;
};

