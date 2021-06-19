// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCController.h"
#include "BehaviorTree/BehaviorTree.h"


void ANPCController::BeginPlay() 
{
    Super::BeginPlay();
    if(BTree!=nullptr)
    {
        RunBehaviorTree(BTree);
    }
}
