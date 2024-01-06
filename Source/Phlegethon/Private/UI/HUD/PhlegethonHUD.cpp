#include "UI/HUD/PhlegethonHUD.h"
#include "UI/Widget/PhlegethonUserWidget.h"

void APhlegethonHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	check(Widget);
	Widget->AddToViewport();
}
