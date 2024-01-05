#include "Player/PhlegethonPlayerState.h"
#include "AbilitySystem/PhlegethonAbilitySystemComponent.h"
#include "AbilitySystem/PhlegethonAttributeSet.h"

APhlegethonPlayerState::APhlegethonPlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UPhlegethonAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UPhlegethonAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* APhlegethonPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
