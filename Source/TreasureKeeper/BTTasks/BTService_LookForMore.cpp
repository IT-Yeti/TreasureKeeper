// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_LookForMore.h"
#include "AIController.h"
#include "TreasureKeeper/Actors/Treasure.h"
#include "TreasureKeeper/Characters/NPCCore.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_LookForMore::UBTService_LookForMore() 
{
    NodeName = "Look for more treasures";
}

void UBTService_LookForMore::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) 
{
    if(OwnerComp.GetBlackboardComponent()->GetValueAsObject(TEXT("Treasure"))!=nullptr)
    {
        return;
    }

    APawn* NPCPawn = OwnerComp.GetAIOwner()->GetPawn();
    ANPCCore* NPC = Cast<ANPCCore>(NPCPawn);
    if(NPC)
    {
        if(NPC->Treasures.Num()>0)
        {
            OwnerComp.GetBlackboardComponent()->SetValueAsObject(TEXT("Treasure"),NPC->Treasures[0]);
        }
    }
}
