#include "PhysicsEngine.h"
#include "Engine/Components/PhysicsComponent.h"



PhysicsEngine::PhysicsEngine()
{

}

PhysicsEngine* PhysicsEngine::sInstance = nullptr;

void PhysicsEngine::UpdatePhysics()
{
	for (std::shared_ptr<PhysicsComponent> firstComponent : mPhysicsComponents)
	{
		firstComponent->ComputePhysics();
	}
}

void PhysicsEngine::AddPhysicsComponent(std::shared_ptr<PhysicsComponent> componentToAdd)
{
	mPhysicsComponents.push_back(componentToAdd);
}
