#include "Player/PhlegetonPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

APhlegetonPlayerController::APhlegetonPlayerController()
{
	bReplicates = true;
}

void APhlegetonPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(PhlegetonContext); //assert not null

	//Set up enhanced input subsystem
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		 GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(PhlegetonContext, 0);

	//Set up mouse cursor options
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	//Set up input mode data
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void APhlegetonPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction,
	                                   ETriggerEvent::Triggered,
	                                   this,
	                                   &APhlegetonPlayerController::Move);
}

void APhlegetonPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
