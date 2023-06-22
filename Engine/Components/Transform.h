#pragma once
#include "CoreMinimal.h"
#include "Engine/Components/Component.h"
#include "Engine/Public/EngineTypes.h"

class Transform : public Component
{
public:

	Transform() = delete;
	Transform(std::shared_ptr<GameObject> owner, exVector2 loc, exVector2 rot, exVector2 scale);

	virtual EComponentTypes GetComponentType() const override;

	virtual void BeginPlay() override;
	virtual void EndPlay() override;
	virtual void Tick() override;

	exVector2 GetPosition() const;
	exVector2 GetRotation() const;
	exVector2 GetScale() const;

	void SetPosition(exVector2 pos);
	void SetRotation(exVector2 rot);
	void SetScale(exVector2 scale);

private:

	exVector2 mLocation;
	exVector2 mScale;
	exVector2 mRotation;
};

