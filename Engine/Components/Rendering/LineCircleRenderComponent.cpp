#include "LineCircleRenderComponent.h"
#include "Engine/Components/Transform.h"
#include "Engine/GameFramework/GameObject.h"


LineCircleRenderComponent::LineCircleRenderComponent(std::shared_ptr<GameObject> owner, float mRadius, exColor color)
	: RenderingComponent(owner, color)
{
	this->mRadius = mRadius;

}


void LineCircleRenderComponent::Render(exEngineInterface* engineInterface)
{
	if (!mTransform)
		return;
	
	// let Pedro add the layer parameter
	engineInterface->DrawLineCircle(mTransform.get()->GetPosition(), mRadius, mColor, 1);
	
}