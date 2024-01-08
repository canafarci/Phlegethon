#include "UI/WidgetController/PhlegethonWidgetController.h"

void UPhlegethonWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WidgetControllerParams)
{
	PlayerController = WidgetControllerParams.PlayerController;
	PlayerState = WidgetControllerParams.PlayerState;
	AbilitySystemComponent = WidgetControllerParams.AbilitySystemComponent;
	AttributeSet = WidgetControllerParams.AttributeSet;
}

void UPhlegethonWidgetController::BroadcastInitialValues()
{
}

void UPhlegethonWidgetController::BindCallbacksToDependencies()
{
}
