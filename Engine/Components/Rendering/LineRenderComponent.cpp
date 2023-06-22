#include "LineRenderComponent.h"
#include "Engine/Components/Transform.h"
#include "Engine/GameFramework/GameObject.h"

LineRenderComponent::LineRenderComponent(std::shared_ptr<GameObject> owner, float length, float thickness, exColor color)
	: RenderingComponent(owner, color)
{
	mLength = length;
	mThickness = thickness;
}

void LineRenderComponent::Render(exEngineInterface* engineInterface)
{
	if (!mTransform)
		return;

	const exVector2 p1 = exVector2{ mTransform.get()->GetPosition().x - (mLength / 2.f),
		mTransform.get()->GetPosition().y - (mThickness / 2.f) };
	const exVector2 p2 = exVector2{ mTransform.get()->GetPosition().x + mLength,
		mTransform.get()->GetPosition().y + mThickness };


	engineInterface->DrawLine(p1, p2, mColor, 1);
}
