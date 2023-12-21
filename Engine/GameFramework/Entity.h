#pragma once

#include "CoreMinimal.h"

#include "Engine/Components/Component.h"
#include "Engine/Components/Transform.h"
#include "Engine/Components/PhysicsComponent.h"
#include "Engine/Components/Rendering/RenderingComponent.h"
#include "Engine/Components/Rendering/BoxRenderComponent.h"



#include <type_traits>


struct FTransform
{
	exVector2 position;
	exVector2 rotation;
	exVector2 scale;
};

/// <summary>
/// Entity class is the object that can be spawned in the virtual game world.
/// @ It can compose components to add behavior.
/// </summary>
class Entity : public std::enable_shared_from_this<Entity>
{
public:

	Entity(FTransform transform);

	~Entity();

	// Game event functions
	virtual void WorldEnter(); // WorldEnter
	virtual void WorldExit(); // WorldExit
	virtual void Tick();

	// this template class can only be of type component
	template <class T = Component>
	std::shared_ptr<T> FindComponentByType()
	{
		for (std::shared_ptr<Component> itr : mComponent)
		{
			if (std::shared_ptr<T> var = std::dynamic_pointer_cast<T>(itr))
			{
				return var;
			}
		}
		return nullptr;
	}

	// Component helper functions
	
	// C++ 20 syntax
	// std::derived_from<Class to derive from> or else use class "class T"
	// typename...args = varadic arguments
	template<std::derived_from<Component> T, typename... Args>
	std::shared_ptr<T> AddComponent(Args... arguments)
	{
		std::shared_ptr<T> componentToAdd = std::make_shared<T>(shared_from_this(), arguments...);
		mComponent.push_back(componentToAdd);
		componentToAdd->BeginPlay();
		return componentToAdd;
	}


	void RemoveComponent(std::shared_ptr<Component> componentToRemove);
	

	void Destroy();

protected:

	std::shared_ptr<Transform> mTransformComp;
	FTransform transform;
private:
	ComponentList mComponent;
};

