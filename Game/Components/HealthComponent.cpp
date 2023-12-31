#include "HealthComponent.h"

HealthComponent::HealthComponent(std::shared_ptr<Entity> owner, int maxHealth) : Component(owner)
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
	//printf("%s", __FUNCTION__);
	OnTakeDamageDelegate(damageToDeal);
}

int HealthComponent::GetCurrentHealth()
{
	return mCurrHealth;
}
