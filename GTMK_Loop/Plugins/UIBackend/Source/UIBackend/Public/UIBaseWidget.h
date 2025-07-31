// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIBaseWidget.generated.h"

class UUIManager;

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FOnRemovedViewport, UUIBaseWidget, OnRemovedFromViewport);

/**
 * 
 */
UCLASS()
class UIBACKEND_API UUIBaseWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	/*
	* Called when the Widget gets removed from the viewport
	*/
	UPROPERTY(BlueprintAssignable, Category = "UI")
	FOnRemovedViewport OnRemovedFromViewport;

protected:
	/*
	* The Manager that is managing this Widget
	*/
	UPROPERTY(BlueprintReadOnly, Category = "UI")
	TObjectPtr<UUIManager> Manager;

	/*
	* Does this widget pause the game world?
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	bool PauseWorld;

public:

	/*
	* Sets the UIManager when it is initially null
	*/
	void SetUIManager(UUIManager* UIManager);

	/*
	* Returns PauseWorld
	*/
	bool GetPauseWorld() const;

	/*
	* Switches the Widget to the NewWidget class, as long as it is in the UIManager's instanciated classes
	*/
	UFUNCTION(BlueprintCallable, Category = "UI")
	void SwitchWidget(TSubclassOf<UUIBaseWidget> NewWidget);

};
