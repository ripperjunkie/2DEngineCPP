#include "CircleColliderComponent.h"
#include "Engine/Colliders/BoxColliderComponent.h"
#include "Engine/GameFramework/Entity.h"
#include "Engine/Components/Transform.h"

CircleColliderComponent::CircleColliderComponent(std::shared_ptr<Entity> owner, float radius)
	: CollisionComponent(owner)
{
	mRadius = radius;
}

EComponentTypes CircleColliderComponent::GetComponentType() const
{
	return EComponentTypes::CircleShape;
}

float CircleColliderComponent::GetRadius() const
{
	return mRadius;
}

void CircleColliderComponent::BeginPlay()
{
	CollisionComponent::BeginPlay();

}


void CircleColliderComponent::Tick()
{
	Component::Tick();

}


bool CircleColliderComponent::IsCollisionDetected(std::shared_ptr<CollisionComponent> otherComponent)
{
	// check if it's the same component
	if (this == &*otherComponent)
	{
		return false;
	}

	// check if it's the owner
	//if (this->GetOwner() == otherComponent->GetOwner())
	//	return false;


	// Get transform component
	std::shared_ptr<Transform> ownerTransform = mOwner->FindComponentByType<Transform>();
	std::shared_ptr<Transform> otherTransform = otherComponent->GetOwner()->FindComponentByType<Transform>();

	auto tst = otherComponent->GetOwner();



	if (ownerTransform == nullptr || otherTransform == nullptr)
	{
		return false;
	}

	// Test collision against other circle collision
	if (std::shared_ptr<CircleColliderComponent> otherCircleComponent = otherComponent->GetOwner()->FindComponentByType<CircleColliderComponent>())
	{
		// distance between both
		float distanceX = otherTransform->GetPosition().x - ownerTransform->GetPosition().x;
		float distanceY = otherTransform->GetPosition().y - ownerTransform->GetPosition().y;

		//Get a normalized distance with pythagoras 
		float normalizedDistance = sqrt((distanceX * distanceX) + (distanceY * distanceY));

		//Return true if said distance is less than the radius of the other component
		bool collisionCheck = normalizedDistance - GetRadius() <= GetRadius();

		return collisionCheck;
	}

	// Test collision against other box collision
	if (std::shared_ptr<BoxColliderComponent> otherBoxComponent = otherComponent->GetOwner()->FindComponentByType<BoxColliderComponent>())
	{
		//Get dimensions of box owner
		float otherWidth = otherBoxComponent->GetWidth();
		float otherHeight = otherBoxComponent->GetHeight();

		//Get Position for the box owner (x and y)
		float ownerXPosition = ownerTransform->GetPosition().x;
		float ownerYPosition = ownerTransform->GetPosition().y;

		//Get position for the circle component (x and y)
		float otherXPosition = otherTransform->GetPosition().x;
		float otherYPosition = otherTransform->GetPosition().y;

		//testing to see which is the nearest edge to the other circle
		float testX = otherXPosition;
		float testY = otherYPosition;

		//Check to see which is the closest edge (X position)
		if (otherXPosition < ownerXPosition - otherWidth / 2) { testX = ownerXPosition - otherWidth / 2; }
		else if (otherXPosition > ownerXPosition + otherWidth / 2) { testX = ownerXPosition + otherWidth / 2; }

		//Check to see which is the closest edge (Y position)
		if (otherYPosition < ownerYPosition - otherHeight / 2) { testY = ownerYPosition - otherHeight / 2; }
		else if (otherYPosition > ownerYPosition + otherHeight / 2) { testY = ownerYPosition + otherHeight / 2; }

		//Calculate distance between the nearest edge and the actual components
		float distanceX = otherXPosition - testX;
		float distanceY = otherYPosition - testY;

		//Get a normalized distance with pythagoras 
		float normalizedDistance = sqrt((distanceX * distanceX) + (distanceY * distanceY));


		//Return true if said distance is less than the radius of the other component
		bool collisionCheck = normalizedDistance <= GetRadius();

		return collisionCheck;
	}
	return false;
}

void CircleColliderComponent::EndPlay()
{
}