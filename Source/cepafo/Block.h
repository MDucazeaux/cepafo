// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "cepafo.h"
#include "GameFramework/Actor.h"
#include "Block.generated.h"

UCLASS()
class CEPAFO_API ABlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlock();
	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block")
		EBType BlockType;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

	/*int32 BNumberRepetition;
	int32 BNumbre;*/
	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	EBType GetBlockType();

};
