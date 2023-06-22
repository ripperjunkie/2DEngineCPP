#include "GameObject.h"
#include "Engine/Managers/GameObjectManager.h"



GameObject::GameObject(FTransform transform)
{
	this->transform = transform;
}

GameObject::~GameObject()
{

}

void GameObject::BeginPlay()
{
	if (!mTransformComp)
	{		
		mTransformComp = AddComponent<Transform>(transform.position, transform.rotation, transform.scale);
		//if (mTransformComp)
		//{
		//	mTransformComp->SetPosition(transform.position);
		//	mTransformComp->SetRotation(transform.rotation);
		//	mTransformComp->SetScale(transform.scale);
		//}
	}

	for (std::shared_ptr<Component> componentItr : mComponent)
	{
		componentItr->BeginPlay();
	}
}

void GameObject::EndPlay()
{
	for (std::shared_ptr<Component> componentItr : mComponent)
	{
		componentItr->EndPlay();
	}
}

void GameObject::Tick()
{
	for (std::shared_ptr<Component> componentItr : mComponent)
	{
		componentItr->Tick();
	}
}

void GameObject::RemoveComponent(std::shared_ptr<Component> componentToRemove)
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
