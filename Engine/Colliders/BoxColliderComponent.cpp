#include "BoxColliderComponent.h"
#include "Engine/Colliders/CircleColliderComponent.h"
#include "Engine/GameFramework/GameObject.h"
#include "Engine/Components/Transform.h"

BoxColliderComponent::BoxColliderComponent(std::shared_ptr<GameObject> owner, float width, float height)
	: CollisionComponent(owner)
{
	mWidth = width;
	mHeight = height;
}

EComponentTypes BoxColliderComponent::GetComponentType() const
{
	return EComponentTypes::BoxShape;
}

float BoxColliderComponent::GetWidth() const
{
	return mWidth;
}

float BoxColliderComponent::GetHeight() const
{
	return mHeight;
}

float BoxColliderComponent::GetArea() const
{
	return mWidth * mHeight;
}

void BoxColliderComponent::BeginPlay()
{
	CollisionComponent::BeginPlay();
}


void BoxColliderComponent::Tick()
{
	CollisionComponent::Tick();

}


void BoxColliderComponent::EndPlay()
{
}

bool BoxColliderComponent::IsCollisionDetected(std::shared_ptr<CollisionComponent> otherComponent)
{
	if (this == &*otherComponent)
	{
		return false;
	}

	// Get transform component
	std::shared_ptr<Transform> ownerTransform = mOwner->FindComponentByType<Transform>();
	std::shared_ptr<Transform> otherTransform = otherComponent->GetOwner()->FindComponentByType<Transform>();

	if (ownerTransform == nullptr || otherTransform == nullptr)
	{
		return false;
	}

	// Comparing it against a box collision
	if (std::shared_ptr<BoxColliderComponent> otherBoxComp = otherComponent->GetOwner()->FindComponentByType<BoxColliderComponent>())
	{
		// check if it is within bounds
		bool widthCheck = ownerTransform->GetPosition().x + (this->GetWidth() / 2) >= otherTransform->GetPosition().x - (otherBoxComp->GetWidth() / 2) &&
			ownerTransform->GetPosition().x - (this->GetWidth() / 2) <= otherTransform->GetPosition().x + (otherBoxComp->GetWidth() / 2);

		bool heigthCheck = ownerTransform->GetPosition().y + (this->GetHeight() / 2) >= otherTransform->GetPosition().y - (otherBoxComp->GetHeight() / 2) &&
			ownerTransform->GetPosition().y - (this->GetHeight() / 2) <= otherTransform->GetPosition().y + (otherBoxComp->GetHeight() / 2);

		return widthCheck && heigthCheck;
	}


	// Comparing it against a circle collision
	if (std::shared_ptr<CircleColliderComponent> otherCircleComponent = otherComponent->GetOwner()->FindComponentByType<CircleColliderComponent>())
	{
		//Get dimensions of box owner
		float ownerWidth = this->GetWidth();
		float ownerHeight = this->GetHeight();

		//Get Position for the box owner (x and y)
		float ownerXPosition = ownerTransform->GetPosition().x;
		float ownerYPosition = ownerTransform->GetPosition().y;

		//Get dimensions of the circle component (radius)
		float otherRadius = otherCircleComponent->GetRadius();

		//Get position for the circle component (x and y)
		float otherXPosition = otherTransform->GetPosition().x;
		float otherYPosition = otherTransform->GetPosition().y;

		//testing to see which is the nearest edge to the other circle
		float testX = otherXPosition;
		float testY = otherYPosition;

		//Check to see which is the closest edge (X position)
		if (otherXPosition < ownerXPosition - ownerWidth / 2) { testX = ownerXPosition - ownerWidth / 2; }
		else if (otherXPosition > ownerXPosition + ownerWidth / 2) { testX = ownerXPosition + ownerWidth / 2; }

		//Check to see which is the closest edge (Y position)
		if (otherYPosition < ownerYPosition - ownerHeight / 2) { testY = ownerYPosition - ownerHeight / 2; }
		else if (otherYPosition > ownerYPosition + ownerHeight / 2) { testY = ownerYPosition + ownerHeight / 2; }

		//Calculate distance between the nearest edge and the actual components
		float distanceX = otherXPosition - testX;
		float distanceY = otherYPosition - testY;

		//Get a normalized distance with pythagoras 
		float totDistance = sqrt((distanceX * distanceX) + (distanceY * distanceY));


		//Return true if said distance is less than the radius of the other component
		bool collisionCheck = totDistance <= otherRadius;

		return collisionCheck;
	}

	return false;
}