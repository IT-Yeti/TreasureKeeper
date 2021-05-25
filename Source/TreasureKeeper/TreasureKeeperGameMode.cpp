// Copyright Epic Games, Inc. All Rights Reserved.

#include "TreasureKeeperGameMode.h"
#include "TreasureKeeperCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATreasureKeeperGameMode::ATreasureKeeperGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
