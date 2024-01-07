#include "Character/PlayerCharacter.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/PhlegethonPlayerState.h"
#include "Player/PhlegetonPlayerController.h"
#include "UI/HUD/PhlegethonHUD.h"

APlayerCharacter::APlayerCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	//Init ability actor info for the server
	InitAbilityActorInfo();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	//Init ability actor info for the client
	InitAbilityActorInfo();
}

void APlayerCharacter::InitAbilityActorInfo()
{
	APhlegethonPlayerState* PhlegethonPlayerState = GetPlayerState<APhlegethonPlayerState>();
	check(PhlegethonPlayerState);
	AbilitySystemComponent = PhlegethonPlayerState->GetAbilitySystemComponent();
	AbilitySystemComponent->InitAbilityActorInfo(PhlegethonPlayerState, this);
	AttributeSet = PhlegethonPlayerState->GetAttributeSet();

	if (APhlegetonPlayerController* PhlegethonPlayerController = Cast<APhlegetonPlayerController>(GetController()))
	{
		if (APhlegethonHUD* PhlegethonHUD = Cast<APhlegethonHUD>(PhlegethonPlayerController->GetHUD()))
		{
			PhlegethonHUD->InitOverlay(PhlegethonPlayerController, PhlegethonPlayerState,
			                           AbilitySystemComponent, AttributeSet);
		}
	}
}
