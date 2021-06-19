// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_PickUpTreasure.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "TreasureKeeper/Actors/Treasure.h"
#include "AIController.h"
#include "TreasureKeeper/Characters/NPCCore.h"
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
        APawn* NPCPawn = OwnerComp.GetAIOwner()->GetPawn();
        ANPCCore* NPCClass = Cast<ANPCCore>(NPCPawn);
        TArray<AActor*>Treasures = NPCClass->Treasures;
        for(AActor* Skarb : Treasures)
        {
            if(Skarb == Treasure)
            {
                NPCClass->Treasures.Remove(Skarb);
            }
        }
        Treasure->Destroy();
        NPCBlackboard->ClearValue(GetSelectedBlackboardKey());
        
    } 
    return EBTNodeResult::Succeeded;
    
}
