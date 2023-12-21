#pragma once
#include "RenderingComponent.h"
class LineCircleRenderComponent : public RenderingComponent
{
public:
	LineCircleRenderComponent(std::shared_ptr<Entity> owner, float mRadius = 1.f, exColor color = { 255,0,0,255 });

	virtual void Render(exEngineInterface* engineInterface) override;

private:
	float mRadius;
};

