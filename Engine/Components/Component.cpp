#include "Component.h"



Component::Component(std::shared_ptr<GameObject> owner)
{
	mOwner = owner;
}

void Component::Tick()
{

}