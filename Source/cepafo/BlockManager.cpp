// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockManager.h"

// Sets default values
ABlockManager::ABlockManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABlockManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlockManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABlockManager::AddBlock(ABlock* Block)
{
}

void ABlockManager::RemoveBlock(ABlock* Block)
{
}

void ABlockManager::Execute()
{
}

