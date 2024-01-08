#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/PhlegethonAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UPhlegethonAttributeSet* PhlegethonAttributeSet = Cast<UPhlegethonAttributeSet>(AttributeSet);
	const float Health = PhlegethonAttributeSet->GetHealth();
	const float MaxHealth = PhlegethonAttributeSet->GetMaxHealth();

	OnHealthChanged.Broadcast(Health);
	OnMaxHealthChanged.Broadcast(MaxHealth);
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	
}
