#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhlegethonEffectActor.generated.h"

class UGameplayEffect;
class USphereComponent;

UCLASS()
class PHLEGETHON_API APhlegethonEffectActor : public AActor
{
	GENERATED_BODY()

public:
	APhlegethonEffectActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, const TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
};
