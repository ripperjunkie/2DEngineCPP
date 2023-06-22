#include "Component.h"



Component::Component(std::shared_ptr<GameObject> owner)
{
	mOwner = owner;
}

void Component::Tick()
{

}

//Remembering smart pointers
//std::unique_ptr<int> a = std::make_unique<int>(20);
//std::unique_ptr<int> b = std::move(a); //now the owner is b and a becomes a null pointer

//std::shared_ptr<int> a1 = std::make_shared<int>(50);
//std::shared_ptr<int> b1 = a1;

//std::weak_ptr<int>a2 = a1;
//a2.lock(); // checks if it's ok to use it or not