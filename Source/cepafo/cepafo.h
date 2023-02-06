// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"


UENUM()
enum class EBType
{
	ESequence,
	ENumber,
	EArrow,
	EBloc,
	EN,
};




UENUM()
enum class EDirection
{
	ERight,
	ELeft,
	EUp,
	EDown,
	ENull
};