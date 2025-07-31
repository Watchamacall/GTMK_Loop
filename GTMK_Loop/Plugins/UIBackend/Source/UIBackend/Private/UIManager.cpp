// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"
#include "UIBaseWidget.h"
#include <Kismet/GameplayStatics.h>


// Sets default values for this component's properties
UUIManager::UUIManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUIManager::BeginPlay()
{
	Super::BeginPlay();

	if (AvailableWidgets.Num() < 1)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No widgets to create, make sure this isn't a mistake"));
		return;
	}

	// Creating the widgets and setting them up
	for (size_t i = 0; i < AvailableWidgets.Num(); i++)
	{
		InstanciatedWidgets.Add(CreateWidget<UUIBaseWidget>(GetWorld(), AvailableWidgets[i], AvailableWidgets[i]->GetFName()));

		InstanciatedWidgets[i]->SetUIManager(this);
	}
	
	SetPrimaryWidgetFromClass(StartWidget);
}

void UUIManager::SetPrimaryWidget(UUIBaseWidget* NewWidget)
{
	if (!InstanciatedWidgets.Contains(NewWidget) || NewWidget == nullptr)
	{
		FString DebugMessage = "Chosen widget is not a valid widget to show on screen. Ensure this is corrected";
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, DebugMessage);
		return;
	}

	if (CurWidget)
	{
		CurWidget->OnRemovedFromViewport.Broadcast();
		CurWidget->RemoveFromParent();
	}
	NewWidget->AddToViewport(0);

	PauseWorld(NewWidget->GetPauseWorld());

	PrevWidget = CurWidget;

	CurWidget = NewWidget;
}

void UUIManager::SetPrimaryWidgetFromClass(TSubclassOf<UUIBaseWidget> NewWidget)
{
	SetPrimaryWidget(GetInstanciatedWidget(NewWidget));
}

UUIBaseWidget* UUIManager::GetInstanciatedWidget(TSubclassOf<UUIBaseWidget> WidgetClass) const
{
	for (auto InstanciatedWidget : InstanciatedWidgets)
	{
		if (InstanciatedWidget->IsA(WidgetClass))
		{
			return InstanciatedWidget;
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The Widget Class was not found in WidgetClass"));
	return nullptr;
}

UUIBaseWidget* UUIManager::GetCurrentWidget() const
{
	return CurWidget;
}

TSubclassOf<UUIBaseWidget> UUIManager::GetPlayerHUD() const
{
	return PlayerHUD;
}

void UUIManager::PauseWorld(bool ShouldPause) const
{
	if (TObjectPtr<APlayerController> Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		//If we already match then we don't need to do any changes
		if (Controller->bShowMouseCursor == ShouldPause)
			return;
		UGameplayStatics::SetGamePaused(GetWorld(), ShouldPause);

		ShouldPause ? Controller->SetInputMode(FInputModeGameAndUI()) : Controller->SetInputMode(FInputModeGameOnly());

		Controller->bShowMouseCursor = ShouldPause;
	}
}

void UUIManager::TriggerPause()
{
	if (!PlayerHUD || !PauseHUD)
		return;

	//CHANGE THIS SO IT ACTUALLY WORKS WITH THE PAUSE MENU WORKING THINGY
	SetPrimaryWidgetFromClass(CurWidget->GetClass() == PlayerHUD ? PauseHUD : PlayerHUD);
}

