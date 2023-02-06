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

private:
	virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
};
