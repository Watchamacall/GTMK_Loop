// Copyright Epic Games, Inc. All Rights Reserved.

#include "GTMK_LoopGameMode.h"
#include "GTMK_LoopCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGTMK_LoopGameMode::AGTMK_LoopGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
