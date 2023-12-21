#pragma once
#include "Engine/Components/Component.h"
#include "Engine/Public/EngineInterface.h"


class Transform;

// the public std::enable_shared_from_this<RenderingComponent> is for 
// so that we can use shared_from_this()
class RenderingComponent : public Component, public std::enable_shared_from_this<RenderingComponent> 
{	
	friend class Entity;
public:
	virtual void Render(exEngineInterface* engineInterface){}
	RenderingComponent(std::shared_ptr<Entity> owner, exColor color = exColor{255,0,0,255});
	RenderingComponent() = delete;


	void SetColor(exColor color);

	/* Helper functions */
	std::shared_ptr<Transform> GetTransform() const
	{
		return mTransform;
	}

private:

	virtual EComponentTypes GetComponentType() const;

	virtual void EndPlay();
	virtual void Tick();


protected:
	virtual void BeginPlay();
	exColor mColor;
	std::shared_ptr< Transform> mTransform;
	int mRenderLayer = 0;
};

