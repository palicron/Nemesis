// Copyright Epic Games, Inc. All Rights Reserved.

#include "NemesisGameMode.h"
#include "NemesisCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANemesisGameMode::ANemesisGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
