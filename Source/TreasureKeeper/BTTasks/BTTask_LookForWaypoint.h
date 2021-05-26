// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_LookForWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class TREASUREKEEPER_API UBTTask_LookForWaypoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTTask_LookForWaypoint();
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
};
