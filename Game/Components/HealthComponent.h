#pragma once
#include "CoreMinimal.h"
#include "Engine/Components/Component.h"

class HealthComponent:public Component
{
public:

	HealthComponent() = delete;
	HealthComponent(std::shared_ptr<GameObject> owner, int maxHealth);


	virtual EComponentTypes GetComponentType() const override;

	virtual void BeginPlay() override;
	virtual void EndPlay() override;
	virtual void Tick() override;

	void TakeDamage(int damageToDeal);
	int GetCurrentHealth();

	int mMaxHealth;
	int mCurrHealth;
};

