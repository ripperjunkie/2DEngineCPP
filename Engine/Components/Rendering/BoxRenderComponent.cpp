#include "BoxRenderComponent.h"
#include "Engine/Components/Transform.h"
#include "Engine/GameFramework/Entity.h"

BoxRenderComponent::BoxRenderComponent(std::shared_ptr<Entity> owner, float width, float height, exColor color /* = */)
	: RenderingComponent(owner, color)
{
	mWidth = width;
	mHeight = height;
}

void BoxRenderComponent::Render(exEngineInterface* engineInterface)
{
	if (!mTransform)
		return;

	const exVector2 p1 = exVector2{ mTransform->GetPosition().x - mWidth / 2,
		mTransform->GetPosition().y - (mHeight / 2.f) };

	const exVector2 p2 = exVector2{ mTransform->GetPosition().x + mWidth / 2,
		mTransform->GetPosition().y + mHeight / 2 };

	engineInterface->DrawBox(p1, p2, mColor, mRenderLayer);
}
