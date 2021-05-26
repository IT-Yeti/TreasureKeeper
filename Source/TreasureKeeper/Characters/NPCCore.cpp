// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCCore.h"

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
	AActor* OwnerActor = GetOwner();
	UE_LOG(LogTemp,Warning,TEXT("MyNameIs: %s"),*OwnerActor->GetName())
	
}

// Called every frame
void ANPCCore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPCCore::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

