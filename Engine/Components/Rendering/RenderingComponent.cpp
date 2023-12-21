#include "RenderingComponent.h"
#include "Engine/Components/Transform.h"
#include "Engine/GameFramework/Entity.h"
#include "Engine/Managers/RenderingEngine.h"


RenderingComponent::RenderingComponent(std::shared_ptr<Entity> owner, exColor color)
    : Component(owner)
{
    this->mColor = color;
}

void RenderingComponent::SetColor(exColor color)
{
    mColor = color;
}

EComponentTypes RenderingComponent::GetComponentType() const
{
    return EComponentTypes::Shape;
}

void RenderingComponent::BeginPlay()
{
    /* The reason why we add the rendering component on begin play is because we wait for the component to be
    attached to some component. This way we can prevent the rendering component to look for components that haven't been
    added yet. */

    if (!mOwner)
        return; 

    //auto a = mOwner->FindComponentByType<RenderingComponent>();
	    RENDER_ENGINE->AddRenderingComponent(shared_from_this());
        mTransform = mOwner->FindComponentByType<Transform>();
}

void RenderingComponent::EndPlay()
{
}

void RenderingComponent::Tick()
{
    Component::Tick();

    //if (std::shared_ptr<Transform> transformComponent = mOwner->FindComponentByType<Transform>())
    //{
    //    // Perform Rendering Logic
    //}
}
