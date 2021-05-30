// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_PickUpTreasure.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "TreasureKeeper/Actors/Treasure.h"
#include "AIController.h"
#include "TreasureKeeper/Characters/NPCController.h"
#include "Kismet/GameplayStatics.h"

UBTTask_PickUpTreasure::UBTTask_PickUpTreasure()
{
    NodeName = "Pick up treasure";
}

EBTNodeResult::Type UBTTask_PickUpTreasure::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
    UBlackboardComponent* NPCBlackboard = OwnerComp.GetBlackboardComponent();
    ATreasure* Treasure = Cast<ATreasure>(NPCBlackboard->GetValueAsObject("Treasure"));
    if(Treasure)
    {
        Treasure->Destroy();
        NPCBlackboard->ClearValue(GetSelectedBlackboardKey());
    } else
    {
        NPCBlackboard->ClearValue("SeeTreasure");
    }
        return EBTNodeResult::Succeeded;
    
}
