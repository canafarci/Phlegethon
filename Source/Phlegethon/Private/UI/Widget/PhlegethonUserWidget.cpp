#include "UI/Widget/PhlegethonUserWidget.h"

void UPhlegethonUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
