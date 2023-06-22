#pragma once
#include "Engine/Components/Component.h"
#include "Engine/Public/EngineInterface.h"

#include <functional>
#include <unordered_map>
#include <vector>

class Transform;
class PhysicsEngine;


class PhysicsComponent : public Component, public std::enable_shared_from_this<PhysicsComponent>
{
	friend class PhysicsEngine;
public:

	PhysicsComponent(std::shared_ptr<GameObject> owner, exVector2 velocity = {0.0f, 0.0f});
	PhysicsComponent() = delete;
	
	virtual void ComputePhysics();

#pragma region Core methods
	virtual EComponentTypes GetComponentType() const;
	virtual void BeginPlay() override;
	virtual void EndPlay() override;
	virtual void Tick() override;
#pragma endregion
	void SetVelocity(exVector2&& newVelocity);
	void AddVelocity(exVector2&& velocity);
	exVector2 GetVelocity() const;

protected:
	bool mIsStatic = false; // can move or not? 
	bool mIsGravityEnabled = false;

private:
	exVector2 mVelocity{0.f,0.f};
};

