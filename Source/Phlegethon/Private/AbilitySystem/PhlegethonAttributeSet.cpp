#include "AbilitySystem/PhlegethonAttributeSet.h"
#include "Net/UnrealNetwork.h"

UPhlegethonAttributeSet::UPhlegethonAttributeSet()
{
	InitHealth(25.f);
	InitMaxHealth(100.f);
	InitMaxMana(100.f);
	InitMana(80.f);
}

void UPhlegethonAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UPhlegethonAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPhlegethonAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPhlegethonAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPhlegethonAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UPhlegethonAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
		//UE_LOG(LogTemp, Warning, TEXT("Health: %f"), NewValue);
	}
	else if (Attribute == GetMaxHealthAttribute())
	{
		//UE_LOG(LogTemp, Warning, TEXT("MaxHealth: %f"), NewValue);
	}
	else if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
		//UE_LOG(LogTemp, Warning, TEXT("Mana: %f"), NewValue);
	}
	else if (Attribute == GetMaxManaAttribute())
	{
		//UE_LOG(LogTemp, Warning, TEXT("MaxMana: %f"), NewValue);
	}
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
