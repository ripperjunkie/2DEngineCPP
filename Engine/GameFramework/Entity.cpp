#include "Entity.h"
#include "Engine/Managers/EntityManager.h"



Entity::Entity(FTransform transform)
{
	this->transform = transform;
}

Entity::~Entity()
{

}

void Entity::WorldEnter()
{
	if (!mTransformComp)
	{		
		mTransformComp = AddComponent<Transform>(transform.position, transform.rotation, transform.scale);
	}

	for (std::shared_ptr<Component> componentItr : mComponent)
	{
		componentItr->BeginPlay();
	}
}

void Entity::WorldExit()
{
	for (std::shared_ptr<Component> componentItr : mComponent)
	{
		componentItr->EndPlay();
	}
}

void Entity::Tick()
{
	for (std::shared_ptr<Component> componentItr : mComponent)
	{
		componentItr->Tick();
	}
}

void Entity::RemoveComponent(std::shared_ptr<Component> componentToRemove)
{
	// Custom built-in c++ iterator to iterate over the component vectors and remove it from the vector list
	auto itrBegin = mComponent.begin();
	auto itrEnd = mComponent.end();

	while (itrBegin != itrEnd)
	{
		++itrBegin;
		if (*itrBegin == componentToRemove)
			mComponent.erase(itrBegin);
	}
}

void Entity::Destroy()
{
	// TODO: Flag this entity to be destroyed by the world manager.
}
