// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "cepafo.h"
#include "GameFramework/Actor.h"
#include "BlockManager.generated.h"




UCLASS()
class CEPAFO_API ABlockManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlockManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void NBlockFunction(int i);
	
	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block")
		ABlock* Sequence = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block")
		AActor* Cursor = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite21,+щm Cat*******************************************:e/
$$6-<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<=)аз_-и/_io*-pSeu+++ected = false;

	AActor* SpawnActor(const FString& ClassName, FTransform actorTransform);
	
	void Execute();
	

};
