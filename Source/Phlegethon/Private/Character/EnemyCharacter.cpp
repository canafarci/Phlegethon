#include "Character/EnemyCharacter.h"
#include "AbilitySystem/PhlegethonAbilitySystemComponent.h"
#include "AbilitySystem/PhlegethonAttributeSet.h"
#include "Phlegethon/Phlegethon.h"

AEnemyCharacter::AEnemyCharacter()
{
	if (USkeletalMeshComponent* SkeletalMeshComponent = GetMesh())
		SkeletalMesh = SkeletalMeshComponent;

	SkeletalMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UPhlegethonAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UPhlegethonAttributeSet>("AttributeSet");
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	check(AbilitySystemComponent);
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AEnemyCharacter::HighlightActor()
{
	SkeletalMesh->SetRenderCustomDepth(true);
	SkeletalMesh->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AEnemyCharacter::UnHighlightActor()
{
	SkeletalMesh->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
