// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UIManager.generated.h"

class UUIBaseWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UIBACKEND_API UUIManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUIManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	/*
	* The widgets that will be active during the game life
	*/
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TArray<TSubclassOf<UUIBaseWidget>> AvailableWidgets;

	/*
	* The instanciated widgets
	*/
	TArray<TObjectPtr<UUIBaseWidget>> InstanciatedWidgets;

	/*
	* The widget to start with when the game starts
	*/
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUIBaseWidget> StartWidget;
	/*
	* The Widget that is used for the Player
	*/
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUIBaseWidget> PlayerHUD;
	/*
	* The Widget that is used for the basic Pause Menu
	*/
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUIBaseWidget> PauseHUD;

	/*
	* The widget that is currently being displayed
	*/
	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	TObjectPtr<UUIBaseWidget> CurWidget;

	/*
	* The widget that was last displayed
	*/
	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	TObjectPtr<UUIBaseWidget> PrevWidget;

public:
	/*
	* Removes the current Widget shown on screen and replaces it with the NewWidget
	*/
	UFUNCTION(BlueprintCallable, Category = "UI")
	void SetPrimaryWidget(UUIBaseWidget* NewWidget);

	/*
	* Sets the Primary Widget based on the class chosen
	*/
	UFUNCTION(BlueprintCallable, Category = "UI")
	void SetPrimaryWidgetFromClass(TSubclassOf<UUIBaseWidget> NewWidget);

	/*
	* Returns the Instanciated Widget that matches the WidgetClass
	*/
	UFUNCTION(BlueprintCallable, Category = "UI")
	UUIBaseWidget* GetInstanciatedWidget(TSubclassOf<UUIBaseWidget> WidgetClass) const;

	/*
	* Returns the current widget that is being displayed
	*/
	UFUNCTION(BlueprintCallable, Category = "UI")
	UUIBaseWidget* GetCurrentWidget() const;

	TSubclassOf<UUIBaseWidget> GetPlayerHUD() const;
	/*
	* Pauses the game if ShouldPause is true
	*/
	void PauseWorld(bool ShouldPause) const;

	void TriggerPause();
};
