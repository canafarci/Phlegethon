#include "Character/EnemyCharacter.h"
#include "Phlegethon/Phlegethon.h"

AEnemyCharacter::AEnemyCharacter()
{
	Super::BeginPlay();
	if (USkeletalMeshComponent* SkeletalMeshComponent = GetMesh())
		SkeletalMesh = SkeletalMeshComponent;

	SkeletalMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
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
