// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/CPP_AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AI_CPP.h"

void ACPP_AIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	AAI_CPP* AI = Cast<AAI_CPP>(GetPawn());

	if (AI)
	{
		AI->GoToNextWaypoint();
		AI->MoveToWaypoint();
	}
}
