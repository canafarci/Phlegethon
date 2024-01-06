#include "AbilitySystem/PhlegethonAttributeSet.h"
#include "Net/UnrealNetwork.h"

UPhlegethonAttributeSet::UPhlegethonAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
	InitMaxMana(100.f);
	InitMana(100.f);
}

void UPhlegethonAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UPhlegethonAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPhlegethonAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPhlegethonAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPhlegethonAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UPhlegethonAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPhlegethonAttributeSet, Health, OldHealth);
}

void UPhlegethonAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPhlegethonAttributeSet, MaxHealth, OldMaxHealth);
}

void UPhlegethonAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPhlegethonAttributeSet, Mana, OldMana);
}

void UPhlegethonAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPhlegethonAttributeSet, MaxMana, OldMaxMana);
}
