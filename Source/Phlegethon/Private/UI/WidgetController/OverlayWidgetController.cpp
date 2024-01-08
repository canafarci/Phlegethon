#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/PhlegethonAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UPhlegethonAttributeSet* PhlegethonAttributeSet = Cast<UPhlegethonAttributeSet>(AttributeSet);
	const float Health = PhlegethonAttributeSet->GetHealth();
	const float MaxHealth = PhlegethonAttributeSet->GetMaxHealth();
	const float Mana = PhlegethonAttributeSet->GetMana();
	const float MaxMana = PhlegethonAttributeSet->GetMaxMana();

	OnHealthChanged.Broadcast(Health);
	OnMaxHealthChanged.Broadcast(MaxHealth);
	OnManaChanged.Broadcast(Mana);
	OnMaxManaChanged.Broadcast(MaxMana);
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UPhlegethonAttributeSet* PhlegethonAttributeSet = Cast<UPhlegethonAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(PhlegethonAttributeSet->GetHealthAttribute()).
	                        AddUObject(this, &UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(PhlegethonAttributeSet->GetMaxHealthAttribute()).
	                        AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(PhlegethonAttributeSet->GetManaAttribute()).
	                        AddUObject(this, &UOverlayWidgetController::ManaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(PhlegethonAttributeSet->GetMaxManaAttribute()).
	                        AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
