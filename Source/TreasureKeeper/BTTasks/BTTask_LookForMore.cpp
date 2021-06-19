// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_LookForMore.h"
#include "AIController.h"
#include "TreasureKeeper/Characters/NPCController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "TreasureKeeper/Actors/Treasure.h"

UBTTask_LookForMore::UBTTask_LookForMore()
{
    NodeName = TEXT("Look For More");
}
