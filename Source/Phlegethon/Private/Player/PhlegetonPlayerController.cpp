#include "Player/PhlegetonPlayerController.h"
#include "EnhancedInputSubsystems.h"

APhlegetonPlayerController::APhlegetonPlayerController()
{
	bReplicates = true;
}

void APhlegetonPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(PhlegetonContext); //assert not null

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(PhlegetonContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
