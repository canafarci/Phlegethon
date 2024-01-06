#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PhlegethonWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

UCLASS()
class PHLEGETHON_API UPhlegethonWidgetController : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="Widget Controler")
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category="Widget Controler")
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category="Widget Controler")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category="Widget Controler")
	TObjectPtr<UAttributeSet> AttributeSet;
};
