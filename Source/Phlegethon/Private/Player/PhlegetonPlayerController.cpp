#include "Player/PhlegetonPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/HighlightableActor.h"

APhlegetonPlayerController::APhlegetonPlayerController()
{
	bReplicates = true;
}

void APhlegetonPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	TraceCursor();
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

void APhlegetonPlayerController::TraceCursor()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);

	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = Cast<IHighlightableActor>(CursorHit.GetActor());

	// If both ThisActor and LastActor are null, there is nothing to do.
	if (ThisActor == nullptr && LastActor == nullptr)
	{
		return;
	}

	// If ThisActor is not equal to LastActor, unhighlight the last actor.
	// This is safe to do even if ThisActor is null, because it means we've moved away from LastActor.
	if (ThisActor != LastActor && LastActor != nullptr)
	{
		LastActor->UnHighlightActor();
	}

	// If ThisActor is not null and it's not the same as LastActor, highlight ThisActor.
	// This includes the case where LastActor is null, as we've moved onto a new actor from no actor.
	if (ThisActor != nullptr && ThisActor != LastActor)
	{
		ThisActor->HighlightActor();
	}
}
