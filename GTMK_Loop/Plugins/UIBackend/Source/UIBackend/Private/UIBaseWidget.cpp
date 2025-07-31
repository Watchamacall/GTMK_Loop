#include "UIBaseWidget.h"
#include "UIManager.h"

void UUIBaseWidget::SetUIManager(UUIManager* UIManager)
{
	if (Manager)
		return;

	Manager = UIManager;
}

bool UUIBaseWidget::GetPauseWorld() const
{
	return PauseWorld;
}

void UUIBaseWidget::SwitchWidget(TSubclassOf<UUIBaseWidget> NewWidget)
{
	Manager->SetPrimaryWidgetFromClass(NewWidget);
}
