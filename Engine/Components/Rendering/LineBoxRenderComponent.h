#pragma once
#include "RenderingComponent.h"

class LineBoxRenderComponent : public RenderingComponent
{
public:
	LineBoxRenderComponent(std::shared_ptr<GameObject> owner, float length = 10.f, float thickness = 1.f, exColor color = { 255,0,0,255 });

	virtual void Render(exEngineInterface* engineInterface) override;

private:
	float mLength;
	float mThickness;

};

