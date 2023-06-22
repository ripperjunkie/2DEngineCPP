#include "TextRenderComponent.h"
#include "Engine/Components/Transform.h"
#include "Engine/GameFramework/GameObject.h"

TextRenderComponent::TextRenderComponent(std::shared_ptr<GameObject> owner,
	int fontID /*= 1*/,
	std::string&& text /*= "hello"*/,
	exColor color /*= { 255,0,0,255 }*/) : RenderingComponent(owner, color)
{
	this->mFontID = fontID;
	this->mText = text;
}

void TextRenderComponent::Render(exEngineInterface* engineInterface)
{
	if (!mTransform)
		return;

	// let Pedro add the layer parameter
	engineInterface->DrawText(mFontID, mTransform.get()->GetPosition(), mText.c_str(), mColor, 1);
}

void TextRenderComponent::SetText(std::string text)
{
	mText = text;
}
