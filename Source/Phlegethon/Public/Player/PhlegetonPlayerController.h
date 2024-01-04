#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PhlegetonPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
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

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputMappingContext> PhlegetonContext;

	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);
};
