#pragma once
#include "RenderingComponent.h"

class BoxRenderComponent : public RenderingComponent
{
public:
	BoxRenderComponent(std::shared_ptr<Entity> owner, 
		float width = 0.0f, float height = 100.0f, exColor color = { 255,0,0,255 });


	virtual void Render(exEngineInterface* engineInterface) override;

	float GetWidth() const {
		return mWidth;
	}
	float GetHeight() const {
		return mHeight;
	}

private:
	float mWidth;
	float mHeight;
};

