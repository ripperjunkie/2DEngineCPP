#include "HealthComponent.h"

HealthComponent::HealthComponent(std::shared_ptr<GameObject> owner, int maxHealth) : Component(owner)
{
	mMaxHealth = maxHealth;
	mCurrHealth = maxHealth;
}

EComponentTypes HealthComponent::GetComponentType() const
{
	return EComponentTypes();
}

void HealthComponent::BeginPlay()
{
}

void HealthComponent::EndPlay()
{
}

void HealthComponent::Tick()
{
}

void HealthComponent::TakeDamage(int damageToDeal)
{
	mCurrHealth -= damageToDeal;
}

int HealthComponent::GetCurrentHealth()
{
	return mCurrHealth;
}
