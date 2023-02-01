// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AI_CPP.h"
#include "CPP_AIController.h"
#include <Kismet/GameplayStatics.h>
#include "AI/Waypoint_CPP.h"

// Sets default values
AAI_CPP::AAI_CPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAI_CPP::BeginPlay()
{
	Super::BeginPlay();
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaypoint_CPP::StaticClass(), Waypoints);
	MoveToWaypoint();
}

// Called every frame
void AAI_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAI_CPP::MoveToWaypoint()
{
	ACPP_AIController* AIController = Cast<ACPP_AIController>(GetController());
	
	if (AIController)
	{
		DrawDebugLine(GetWorld(),GetActorLocation(), Waypoints[CurrentWaypoint]->GetActorLocation(), FColor::Red);
		if (CurrentWaypoint <= Waypoints.Num())
		{
			for (AActor* Waypoint : Waypoints)
			{
				AWaypoint_CPP* WaypointItr = Cast<AWaypoint_CPP>(Waypoint);
				if (WaypointItr)
				{
					if (WaypointItr->GetWaypointOrder() == CurrentWaypoint)
					{
						AIController->MoveToActor(WaypointItr, 5.f, false);
						break;
					}
				}
			}
		}
	}
}

void AAI_CPP::GoToNextWaypoint()
{
	CurrentWaypoint = (CurrentWaypoint + 1) % Waypoints.Num();
	isMoving = true;
}

void AAI_CPP::KillOnTouch()
{
	
}

