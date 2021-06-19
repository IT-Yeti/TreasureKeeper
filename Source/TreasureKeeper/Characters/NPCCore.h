// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPCCore.generated.h"

UCLASS()
class TREASUREKEEPER_API ANPCCore : public ACharacter
{
	GENERATED_BODY()
	
public:
	ANPCCore();
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="AI")
	TArray<AActor*> Waypoints;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	TArray<AActor*> Treasures;
	class AAIController* NPCAIController;
	class UBlackboardComponent* Blackboard;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	
};
