// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockManager.h"
#include "ArrowBlock.h"
#include "NBlock.h"
#include "cepafo.h"
#include "NumberBlock.h"
#include "BlockBlock.h"
#include "SequenceBlock.h"

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
	Blocks.Enqueue(Block);
}

void ABlockManager::RemoveBlock(ABlock* Block)
{
	Blocks.Dequeue(Block);
}

EBType ABlockManager::ReturnBlockType(ABlock* Block)
{
	return Block->GetBlockType();
}

void ABlockManager::Execute()
{
	ABlock* block = nullptr;
	Blocks.Dequeue(block);
	switch (block->GetBlockType())
	{

	case EBType::ESequence:
		//TODO
		break;
	case EBType::ENumber:
		//TODO
		
		break;
	case EBType::EArrow:
		//TODO
		break;
	case EBType::EBloc:
		//TODO
		break;
	case EBType::EN:
		//TODO
		break;
	default:
		break;
	}

	
}

