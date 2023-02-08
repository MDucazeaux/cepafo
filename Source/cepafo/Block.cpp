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



	switch (GetDirection())
	{
	case EDirection::ENull:
		break;
		
	case EDirection::ERight:
		break;
	case EDirection::ELeft:
		SetActorRotation(FRotator( 180.f,0, 0)); 
		break;
	case EDirection::EUp:
		SetActorRotation(FRotator(90.f,0,0));
		break;
	case EDirection::EDown:
		SetActorRotation(FRotator(-90.f,0, 0));
		break;
	default:
		break;
	}
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
	
	if (this->GetBlockType() == EBType::ESequence)
	{
		if (Cast<ABlock>(OtherActor))
		{


			if (Cast<ABlock>(OtherActor)->GetBlockType() != EBType::ESequence)
			{

				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("nuveriobzbktosjmrzgrntui"));
				Blocks.Add(Cast<ABlock>(OtherActor));
				//SetActorHiddenInGame(OtherActor);
				OtherActor->SetActorLocation(FVector(1000.f, 5000.f, -1000.f));
				
				Cast<ABlock>(OtherActor)->SphereComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
				//Cast<AActor>(OtherActor)->EnableCollision(false);
				InSequence = true;

				//AActor::DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

			}
			else
			{
				InSequence = false;
			}
		}
	}
		
		
	if (this->GetBlockType() == EBType::EN)
	{
		if (Cast<ABlock>(OtherActor))
		{
			if (Cast<ABlock>(OtherActor)->GetBlockType() != EBType::ESequence)
			{


				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("nuveriobzbktosjmrzgrntui"));
				BlockInN.Add(Cast<ABlock>(OtherActor));
				//OtherActor->SetHidden(true);
				//SetActorHiddenInGame(OtherActor);
				OtherActor->SetActorLocation(FVector(1000.f, 5000.f, -1000.f));
				Cast<ABlock>(OtherActor)->SphereComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
				//Cast<AActor>(OtherActor)->EnableCollision(false);
				InBlockN = true;
				DoOnce = false;


			}
			else 
			{
				InBlockN = false;
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

