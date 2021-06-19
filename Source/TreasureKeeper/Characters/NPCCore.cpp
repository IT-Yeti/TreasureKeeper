// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCCore.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "GameFramework/Pawn.h"

// Sets default values
ANPCCore::ANPCCore()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANPCCore::BeginPlay()
{
	Super::BeginPlay();
	AController* NPCController = GetController();
	NPCAIController = Cast<AAIController>(NPCController);
	Blackboard = NPCAIController->GetBlackboardComponent();
}

// Called every frame
void ANPCCore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(Blackboard->GetValueAsObject(TEXT("Treasure"))==nullptr)
	{
		if(Treasures.Num()>0)
		{
			for(AActor* Treasure : Treasures)
			{
				if(Treasure!=nullptr)
				{
					Blackboard->SetValueAsObject(TEXT("Treasure"),Treasure);
				}
			}
		}
	}
}


