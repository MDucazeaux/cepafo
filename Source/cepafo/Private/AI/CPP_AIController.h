// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CPP_AIController.generated.h"

/**
 * 
 */
UCLASS()
class ACPP_AIController : public AAIController
{
	GENERATED_BODY()
public:
	ACPP_AIController();
	
protected:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "AI")
		class UBehaviorTree* BehaviorTree;
	
	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UBehaviorTreeComponent* BehaviorTreeComponent;
	
	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UBlackboardComponent* BlackboardComponent;
	
	virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
};
