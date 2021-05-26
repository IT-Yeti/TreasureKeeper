// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_LookForWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "TreasureKeeper/Characters/NPCCore.h"
UBTTask_LookForWaypoint::UBTTask_LookForWaypoint() {
    NodeName = "LookForWaypoint";
}

EBTNodeResult::Type UBTTask_LookForWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
    int CurrentWaypointIndex = OwnerComp.GetBlackboardComponent()->GetValueAsInt("WaypointIndex");
    APawn* NPCPawn = OwnerComp.GetAIOwner()->GetPawn();
    ANPCCore* NPCOwner = Cast<ANPCCore>(NPCPawn);
    TArray<AActor*>Waypoints = NPCOwner->Waypoints;
    UE_LOG(LogTemp,Warning,TEXT("Number of items in array: %i"),Waypoints.Num());
    
    if(CurrentWaypointIndex>=Waypoints.Num()-1)
    {
        CurrentWaypointIndex=0;
    }
    else 
    {
        CurrentWaypointIndex++;
    }
    OwnerComp.GetBlackboardComponent()->SetValueAsVector("CurrentWaypoint",Waypoints[CurrentWaypointIndex]->GetActorLocation());
    OwnerComp.GetBlackboardComponent()->SetValueAsInt("WaypointIndex",CurrentWaypointIndex);
    return EBTNodeResult::Succeeded;
}
