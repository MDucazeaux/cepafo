// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/CPP_AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AI_CPP.h"

ACPP_AIController::ACPP_AIController()
{
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
}

void ACPP_AIController::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(BehaviorTree))
	{
		RunBehaviorTree(BehaviorTree);
		BehaviorTreeComponent->StartTree(*BehaviorTree);
	}
}

void ACPP_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (IsValid(Blackboard) && IsValid(BehaviorTree))
	{
		BlackboardComponent->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
	}
}

void ACPP_AIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	AAI_CPP* AI = Cast<AAI_CPP>(GetPawn());

	if (AI)
	{
		AI->GoToNextWaypoint();
		AI->MoveToWaypoint();
	}
}
