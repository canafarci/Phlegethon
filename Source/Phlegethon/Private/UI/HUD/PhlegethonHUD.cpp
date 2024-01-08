#include "UI/HUD/PhlegethonHUD.h"
#include "UI/Widget/PhlegethonUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* APhlegethonHUD::GetOverlayWidgetController(
		const FWidgetControllerParams& WidgetControllerParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WidgetControllerParams);
	}

	return OverlayWidgetController;
}

void APhlegethonHUD::InitOverlay(APlayerController* PlayerController, APlayerState* PlayerState,
                                 UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class Unitialized, check HUD BP"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class Unitialized, check HUD BP"));

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);

	OverlayWidget = Cast<UPhlegethonUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PlayerController, PlayerState,
	                                                     AbilitySystemComponent, AttributeSet);

	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);
	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();

	Widget->AddToViewport();
}
