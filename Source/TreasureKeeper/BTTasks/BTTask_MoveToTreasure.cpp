// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MoveToTreasure.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "GameFramework/Controller.h"

UBTTask_MoveToTreasure::UBTTask_MoveToTreasure() 
{
    NodeName=TEXT("Move To Treasure");
}

EBTNodeResult::Type UBTTask_MoveToTreasure::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
    UObject* Object = OwnerComp.GetBlackboardComponent()->GetValueAsObject(GetSelectedBlackboardKey());
    AActor* Treasure = Cast<AActor>(Object);
    FVector TreasureLocation = Treasure->GetActorLocation();
    float PawnHeight = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation().Z;
    FVector FinalLocation = FVector(TreasureLocation.Z,TreasureLocation.Y,PawnHeight-100);
    OwnerComp.GetAIOwner()->MoveToLocation(FinalLocation,30);
    UE_LOG(LogTemp,Warning,TEXT("MyDestionation is:%s"),*FinalLocation.ToString());
    return EBTNodeResult::Succeeded;
}
