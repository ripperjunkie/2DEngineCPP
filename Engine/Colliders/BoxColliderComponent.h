#pragma once

#include "ColliderComponent.h"

class BoxColliderComponent : public CollisionComponent
{
public:
	BoxColliderComponent() = delete;
	BoxColliderComponent(std::shared_ptr<GameObject> owner, float width = 1.f, float height = 1.f);

	virtual EComponentTypes GetComponentType() const;
	float GetWidth() const;
	float GetHeight() const;
	float GetArea() const; // get box bounds (width * height)

	virtual void BeginPlay() override;
	virtual void EndPlay() override;
	virtual void Tick() override;
	virtual bool IsCollisionDetected(std::shared_ptr<CollisionComponent> otherComponent) override;

private: 

	float mWidth; 
	float mHeight;
};