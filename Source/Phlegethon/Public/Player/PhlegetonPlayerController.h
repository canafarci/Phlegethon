

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PhlegetonPlayerController.generated.h"

class UInputMappingContext;

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
	
private:
	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputMappingContext> PhlegetonContext;
};
