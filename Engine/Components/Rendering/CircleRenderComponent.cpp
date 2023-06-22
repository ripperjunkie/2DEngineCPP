#include "CircleRenderComponent.h"
#include "Engine/Components/Transform.h"
#include "Engine/GameFramework/GameObject.h"


CircleRenderComponent::CircleRenderComponent(std::shared_ptr<GameObject> owner, float mRadius, exColor color)
	: RenderingComponent(owner, color)
{
	this->mRadius = mRadius;	
}

void CircleRenderComponent::Render(exEngineInterface* engineInterface)
{
	if (!mTransform)
		return;

	// let Pedro add the layer parameter
	engineInterface->DrawCircle(mTransform.get()->GetPosition(), mRadius, mColor, mRenderLayer);
	

}

