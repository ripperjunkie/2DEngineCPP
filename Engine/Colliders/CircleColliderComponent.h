#pragma once

#include "ColliderComponent.h"

class CircleColliderComponent : public CollisionComponent
{
public:
	CircleColliderComponent() = delete;
	CircleColliderComponent(std::shared_ptr<GameObject> owner, float radius = 1.f);

	virtual EComponentTypes GetComponentType() const;

	float GetRadius() const;
	virtual void BeginPlay() override;
	virtual void EndPlay() override;
	virtual void Tick() override;
	virtual bool IsCollisionDetected(std::shared_ptr<CollisionComponent> otherComponent) override;

private:

	float mRadius;
};