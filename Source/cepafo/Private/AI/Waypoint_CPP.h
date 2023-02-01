// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Waypoint_CPP.generated.h"

/**
 * 
 */
UCLASS()
class AWaypoint_CPP : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	int GetWaypointOrder();
private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		int m_iWaypointID;
};
