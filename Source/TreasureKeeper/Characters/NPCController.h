// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NPCController.generated.h"

/**
 * 
 */
UCLASS()
class TREASUREKEEPER_API ANPCController : public AAIController
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<AActor*> Treasures;
protected:
	virtual void BeginPlay();
private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* BTree;
};
