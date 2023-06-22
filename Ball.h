#pragma once

#include "CoreMinimal.h"
#include "Engine/GameFramework/GameObject.h"

class Transform;
class PhysicsComponent;
class CircleRenderComponent;
class CircleColliderComponent;

class Ball : public GameObject
{
public:
	Ball(FTransform transform);

	virtual void BeginPlay() override;
	virtual void EndPlay() override;
	virtual void Tick() override;

private:
	std::shared_ptr<Transform> mTransformComp;
	std::shared_ptr<CircleRenderComponent> mCircleRenderComp;
	std::shared_ptr<CircleColliderComponent> mCircleColliderComp;
	std::shared_ptr<PhysicsComponent> mPhysComp;
	float mBallSpeed;
};

