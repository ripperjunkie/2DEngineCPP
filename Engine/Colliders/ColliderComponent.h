#pragma once

#include "Engine/Components/Component.h"
#include "Engine/Public/EngineInterface.h"
#include <functional>
#include <string>

class GameObject;

/* Using this std::funciton allow us to use c++ standard libraries to create function pointers with
more advanced features such as accessing private members*/
typedef std::function<void(std::shared_ptr<GameObject> otherActor)> CollisionEventSignature;

class CollisionComponent : public Component, public std::enable_shared_from_this<CollisionComponent>
{
	friend class CollisionEngine;

public:
	// test
	std::string mNameTest;



	CollisionComponent() = delete;

	virtual EComponentTypes GetComponentType() const override;

	virtual void BeginPlay() override;
	virtual void EndPlay() override;
	virtual void Tick() override;


#pragma region Important Collision Methods
	virtual bool IsCollisionDetected(std::shared_ptr<CollisionComponent> otherComponent) = 0;
	void ListenToCollision(CollisionEventSignature delegateToAdd);
	void StopListenToCollision(CollisionEventSignature delegateToRemove);
	void OnCollisionOverlap(std::shared_ptr<GameObject> otherActor);
#pragma endregion

	CollisionEventSignature collisionDelegate;
	
	bool operator==(CollisionComponent& other) const {
		return (mOwner == other.mOwner);
	}

	std::shared_ptr<GameObject> GetOwner() const
	{
		return mOwner;
	}

protected:
	CollisionComponent(std::shared_ptr<GameObject> owner);

private:
	std::vector<CollisionEventSignature> mCollisionEvents = {};
};


