#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PhlegethonUserWidget.generated.h"

UCLASS()
class PHLEGETHON_API UPhlegethonUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
