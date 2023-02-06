// Fill out your copyright notice in the Description page of Project Settings.


#include "Block.h"
#include "Components/ActorComponent.h"
#include "cepafo.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"
// Sets default values
ABlock::ABlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->InitSphereRadius(100.0f);
	SphereComponent->SetCollisionProfileName(TEXT("SphereBlock"));
	SphereComponent->SetupAttachment(RootComponent);
	
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ABlock::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ABlock::BeginPlay()
{
	Super::BeginPlay();
	

	


}

// Called every frame
void ABlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

}

void ABlock::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
		
		if (Cast<ABlock>(OtherActor)->GetBlockType() != EBType::ESequence)
		{
			if (Cast<ABlock>(OtherActor))
			{
				if (DoOnce)
				{
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("nuveriobzbktosjmrzgrntui"));
					Blocks.Add(Cast<ABlock>(OtherActor));
					OtherActor->SetHidden(true);
					DoOnce = false;
					
				}
				
			}
		}
		
			
		
		
		
		
	
}


EBType ABlock::GetBlockType()
{
	return BlockType;
}

int32 ABlock::GetNumber()
{
	return Numbre;
}

void ABlock::SetNumberRepetition(int32 Number)
{
	NumberRepetition = Number;
}

int32 ABlock::GetNumberRepetition()
{
	return NumberRepetition;
}

EDirection ABlock::GetDirection()
{
	return Direction;
}

