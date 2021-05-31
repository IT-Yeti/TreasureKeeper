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


EBTNodeResult::Type UBTTask_LookForMore::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
    UBlackboardComponent* NPCBlackboard = OwnerComp.GetBlackboardComponent();
    AAIController* AIOwner = OwnerComp.GetAIOwner();
    ANPCController* NPCController = Cast<ANPCController>(AIOwner);
    for(AActor* TreasureActor : NPCController->Treasures)
    {
        ATreasure* NextTreasure = Cast<ATreasure>(TreasureActor);
        if(NextTreasure->isTaken == false)
        {
            NPCBlackboard->SetValueAsObject(GetSelectedBlackboardKey(),NextTreasure);
            break;
        }
    }
    return EBTNodeResult::Succeeded;
}
