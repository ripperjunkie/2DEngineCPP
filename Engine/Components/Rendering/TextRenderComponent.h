#pragma once
#include "RenderingComponent.h"
#include <string>

class TextRenderComponent : public RenderingComponent
{
public:
	TextRenderComponent(std::shared_ptr<GameObject> owner, int fontID = 0, std::string&& text = "hello", exColor color = { 255,0,0,255 });

	virtual void Render(exEngineInterface* engineInterface) override;

	void SetText(std::string text);

private:
	/*int nFontID, const exVector2& v2Position, const char* szText*/
	int mFontID;
	std::string mText;

};

