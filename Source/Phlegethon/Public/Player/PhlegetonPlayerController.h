#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PhlegetonPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class IHighlightableActor;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class PHLEGETHON_API APhlegetonPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APhlegetonPlayerController();
	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	TObjectPtr<IHighlightableActor> LastActor;
	TObjectPtr<IHighlightableActor> ThisActor;

	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputMappingContext> PhlegetonContext;

	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);
	void TraceCursor();
};
