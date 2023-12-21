#include "Component.h"



Component::Component(std::shared_ptr<Entity> owner)
{
	mOwner = owner;
}

void Component::Tick()
{

}