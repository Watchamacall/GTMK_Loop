// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PuzzleEndCPP.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GTMK_LOOP_API UPuzzleEndCPP : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPuzzleEndCPP();

	UFUNCTION(BlueprintImplementableEvent, Category = "Puzzle End")
	void Success();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Puzzle End")
	void Unsuccess();
};
