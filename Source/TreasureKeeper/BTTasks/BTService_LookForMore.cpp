// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_LookForMore.h"
#include "AIController.h"
#include "TreasureKeeper/Characters/NPCController.h"
#include "TreasureKeeper/Actors/Treasure.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_LookForMore::UBTService_LookForMore() 
{
    NodeName = "Look for more treasures";
}

void UBTService_LookForMore::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) 
{
    if(OwnerComp.GetBlackboardComponent()->GetValueAsObject(GetSelectedBlackboardKey())!=nullptr)
    {
        return;
    }
    AAIController* OwnerController = OwnerComp.GetAIOwner();
    ANPCController* NPCController = Cast<ANPCController>(OwnerController);
    for(AActor* TreasureActor : NPCController->Treasures)
    {
        NextTreasure = Cast<ATreasure>(NextTreasure);
        if(OwnerComp.GetAIOwner()->LineOfSightTo(NextTreasure))
        {
            OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(),NextTreasure);
            NextTreasure->isTaken = true;

        }
    }
    
}
