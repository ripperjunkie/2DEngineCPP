#include "Transform.h"

Transform::Transform(std::shared_ptr<GameObject> owner, exVector2 loc, exVector2 rot, exVector2 scale) : Component(owner),
mLocation(loc),
mRotation(rot),
mScale(scale)
{

}

EComponentTypes Transform::GetComponentType() const
{
	return EComponentTypes();
}

void Transform::BeginPlay()
{
}

void Transform::EndPlay()
{
}

void Transform::Tick()
{
	Component::Tick();
}

exVector2 Transform::GetPosition() const
{
	return mLocation;
}

exVector2 Transform::GetRotation() const
{
	return mRotation;
}

exVector2 Transform::GetScale() const
{
	return mScale;
}

void Transform::SetPosition(exVector2 pos)
{
	mLocation = pos;
}

void Transform::SetRotation(exVector2 rot)
{
	mRotation = rot;
}

void Transform::SetScale(exVector2 scale)
{
	mScale = scale;
}



