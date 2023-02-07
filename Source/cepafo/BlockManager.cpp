// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockManager.h"
#include "Block.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "GeneratedCodeHelpers.h"
#include "cepafo.h"

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

void ABlockManager::NBlockFunction(int i)
{
	int numberN = 1;
	for (int h = 0; h < Sequence->Blocks[i]->BlockInN.Num(); h++)
	{




		switch (Sequence->Blocks[h]->BlockInN[0]->GetBlockType())
		{
		case EBType::EBloc:										///////////

			for (int b = 0; b < numberN; b++)
			{
				GetWorld()->SpawnActor(ActorToSpawn, &Cursor->GetTransform());

			}
			numberN = 1;
			break;

		case EBType::EArrow:									///////////

			for (int b = 0; b < numberN; b++)
			{
				if (Sequence->Blocks[h]->GetDirection() == EDirection::ENull)
				{
					Cursor->SetActorLocation(Cursor->GetActorLocation() + FVector());;
				}
				if (Sequence->Blocks[h]->GetDirection() == EDirection::ERight)
				{
					Cursor->SetActorLocation(Cursor->GetActorLocation() + FVector());;
				}
				if (Sequence->Blocks[h]->GetDirection() == EDirection::ELeft)
				{
					Cursor->SetActorLocation(Cursor->GetActorLocation() + FVector());;
				}
				if (Sequence->Blocks[h]->GetDirection() == EDirection::EUp)
				{
					Cursor->SetActorLocation(Cursor->GetActorLocation() + FVector());;
				}
				if (Sequence->Blocks[h]->GetDirection() == EDirection::EDown)
				{
					Cursor->SetActorLocation(Cursor->GetActorLocation() + FVector());;
				}
			}
			numberN = 1;
			break;

		case EBType::ENumber:									///////////

			numberN = Sequence->Blocks[i]->GetNumber();
			break;


		case EBType::EN:
			NBlockFunction(h);
			break;


		default:
			break;
		}





	}
}

// Called every frame
void ABlockManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (IsSelected)
	{
		Execute();
		IsSelected = false;
	}
}





void ABlockManager::Execute()
{
	int number = 1;
	int repetition = 1;
	

	int i = 0;
	if (Sequence->GetBlockType() != EBType::ESequence)
	{
		return;
	}

	for (i = 0; i < Sequence->Blocks.Num(); i++) // For the all the block
	{



		switch (Sequence->Blocks[i]->GetBlockType())
		{

		case EBType::ENumber:									///////////

			number = Sequence->Blocks[i]->GetNumber();
			break;
		case EBType::EArrow:									///////////

			for (int b = 0; b < number; b++)
			{
				if (Sequence->Blocks[i]->GetDirection() == EDirection::ENull)
				{
					return;
				}
				if (Sequence->Blocks[i]->GetDirection() == EDirection::ERight)
				{
					Cursor->SetActorLocation(Cursor->GetActorLocation() + FVector(0 , 0, 100.f));
				}
				if (Sequence->Blocks[i]->GetDirection() == EDirection::ELeft)
				{
					Cursor->SetActorLocation(Cursor->GetActorLocation() + FVector(0, 0, 100.f));
				}
				if (Sequence->Blocks[i]->GetDirection() == EDirection::EUp)
				{
					Cursor->SetActorLocation(Cursor->GetActorLocation() + FVector(0, 100.f, 0));
				}
				if (Sequence->Blocks[i]->GetDirection() == EDirection::EDown)
				{
					Cursor->SetActorLocation(Cursor->GetActorLocation() + FVector(0, -100.f, 0));
				}
			}
			number = 1;
			break;
		case EBType::EBloc:										///////////

			for (int b = 0; b < number; b++)
			{
				GetWorld()->SpawnActor(ActorToSpawn, &Cursor->GetTransform());

			}
			number = 1;
			break;
		case EBType::EN:


			for (int m = 0; m < number; m++)
			{


				NBlockFunction(i);


			}

			number = 1;
			break;
		default:
			break;
		}



	}
}

void ABlockManager::Reset()
{
	
}
