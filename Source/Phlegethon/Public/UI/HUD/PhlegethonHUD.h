#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PhlegethonHUD.generated.h"

struct FWidgetControllerParams;
class UAttributeSet;
class UAbilitySystemComponent;
class UPhlegethonUserWidget;
class UOverlayWidgetController;

UCLASS()
class PHLEGETHON_API APhlegethonHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UPhlegethonUserWidget> OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WidgetControllerParams);

	void InitOverlay(APlayerController* PlayerController, APlayerState* PlayerState,
	                 UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet);

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UPhlegethonUserWidget> OverlayWidgetClass;
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
