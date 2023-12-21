#include "Player.h"

// Engine 
#include "Engine/Colliders/CircleColliderComponent.h"
#include "Engine/Components/Rendering/CircleRenderComponent.h"
#include "Engine/Managers/World.h"
#include "Engine/Public/EpicenterMath.h"

// Game
#include "../Components/HealthComponent.h"
#include "../Components/ScoreComponent.h"

// Entities
#include "Enemy.h"
#include "Food.h"

#define INITIAL_HP 5


Player::Player(FTransform transform) : Entity(transform)
{
	movSpeed = 150.f;
}

void Player::WorldEnter()
{
	Entity::WorldEnter();

	_initialTransform = transform;

	float radius = 15.f;

	// Adding components
	if (!mCircleRenderComp)
	{
		mCircleRenderComp = AddComponent<CircleRenderComponent>(radius);
	}
	
	if (!mCircleColliderComp)
	{
		mCircleColliderComp = AddComponent<CircleColliderComponent>(radius);
	}

	if (!mPhysComp)
	{
		mPhysComp = AddComponent<PhysicsComponent>();
	}

	// Creating health component
	if (!mHealthComp)
	{
		mHealthComp = AddComponent<HealthComponent>(INITIAL_HP);
		if (mHealthComp)
		{			
			mHealthComp->OnTakeDamageDelegate = std::bind(&Player::OnTakeDamage, this, std::placeholders::_1);
		}
	}

	if (!mScoreComp)
	{
		mScoreComp = AddComponent<ScoreComponent>();
	}

	// delegate binding: call listen to collision and pass the delegate
	if (mCircleColliderComp)
	{
		mCircleColliderComp->ListenToCollision(collisionDelegate);
	}
	collisionDelegate = [this](std::shared_ptr<Entity> otherActor)
	{
		this->OnCollisionOverlap(otherActor);
	};

	mCircleRenderComp->SetColor(GREEN);
	initPosition = mTransformComp->GetPosition();


}

void Player::Tick()
{
	Entity::Tick();

	ScreenBounds();
	Movement();
}

void Player::WorldExit()
{
	Entity::WorldExit();
}

void Player::Movement()
{
	// Movement 
	if (!mPhysComp)
	{
		LOG("invalid state comp");

		return;
	}

	if (!pState)
	{
		LOG("invalid state comp");
		return;
	}

	exVector2 currentVelocity = mPhysComp->GetVelocity();

	direction.y = pState[SDL_SCANCODE_W] == 1 ? -1.f : direction.y;
	direction.y = pState[SDL_SCANCODE_S] == 1 ? 1.f : direction.y;
	direction.x = pState[SDL_SCANCODE_D] == 1 ? 1.f : direction.x;
	direction.x = pState[SDL_SCANCODE_A] == 1 ? -1.f : direction.x;

	if (pState[SDL_SCANCODE_W] == 0 && pState[SDL_SCANCODE_S] == 0)
	{
		direction.y = 0;
	}

	if (pState[SDL_SCANCODE_D] == 0 && pState[SDL_SCANCODE_A] == 0)
	{
		direction.x = 0;
	}

	exVector2 normalizedDir = NormalizeVector(direction);

	mPhysComp->SetVelocity({ normalizedDir.x * movSpeed * WORLD->DeltaTimeSeconds(),
		normalizedDir.y * movSpeed * WORLD->DeltaTimeSeconds() });
}

void Player::ScreenBounds()
{
	if (!mTransformComp)
		return;


	exVector2 playerPos = exVector2
	{ 
		mTransformComp->GetPosition().x - mCircleColliderComp->GetRadius(),
		mTransformComp->GetPosition().y - mCircleColliderComp->GetRadius()
	};

	// Reset position if it goes out of bounds
	if (playerPos.y > kViewportHeight || playerPos.x > kViewportWidth
		|| playerPos.y + mCircleColliderComp->GetRadius() < -mCircleColliderComp->GetRadius() || playerPos.x + mCircleColliderComp->GetRadius() < -mCircleColliderComp->GetRadius())
	{
		mTransformComp->SetPosition(initPosition);
	}

}

void Player::OnCollisionOverlap(std::shared_ptr<Entity> otherActor)
{
	// Collided with enemy
	if (std::shared_ptr<Enemy> enemy = std::dynamic_pointer_cast<Enemy>(otherActor))
	{
		if(mHealthComp)
			mHealthComp->TakeDamage(1);

		enemy->ResetPosition();
	}
	// Collided with food
	if (std::shared_ptr<Food> food = std::dynamic_pointer_cast<Food>(otherActor))
	{
		if(mScoreComp)
			mScoreComp->AddScore(1);

		food->ResetPosition();
	}
}

void Player::OnTakeDamage(int DamageTaken)
{
	if (!mHealthComp)
	{
		return;
	}

	// On Game over...
	if (mHealthComp->GetCurrentHealth() <= 0)
	{
		// Reset player position
		this->FindComponentByType<Transform>()->SetPosition(initPosition);


		// reset player score
		if (mScoreComp)
			mScoreComp->SetScore(0);

		// reset player life
		mHealthComp->mCurrHealth = mHealthComp->mMaxHealth;
	}
}
