#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PhlegethonHUD.generated.h"

class UPhlegethonUserWidget;

UCLASS()
class PHLEGETHON_API APhlegethonHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UPhlegethonUserWidget> OverlayWidget;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UPhlegethonUserWidget> OverlayWidgetClass;
};
