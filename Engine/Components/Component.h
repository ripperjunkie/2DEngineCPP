#pragma once

// make use of smart pointers
#include "CoreMinimal.h"


// forward declaration - optimize compile time
class GameObject;

typedef std::vector<std::shared_ptr<class Component>> ComponentList;

enum class EComponentTypes : uint16_t
{
	Transform,
	Physics,
	Shape,
	BoxShape,
	CircleShape,
	StateMachine
};


class Component
{
public:
	Component() = delete;
	Component(std::shared_ptr<GameObject> owner);

	// Mark it as abstract (doesn't require implementation on this class)
	virtual EComponentTypes GetComponentType() const = 0;
	virtual void BeginPlay() = 0;
	virtual void EndPlay() = 0;
	virtual void Tick();

protected:
	std::shared_ptr<GameObject> mOwner;


};