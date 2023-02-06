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
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block")
		EBType BlockType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block")
		int32 NumberRepetition = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block")
		int32 Numbre = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block")
		EDirection Direction = EDirection::ENull;
	
	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Block")
		 class USphereComponent* SphereComponent;
	
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block")
		TArray<ABlock*> Blocks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block")
		TArray<ABlock*> BlockInN;


	
	
	EBType GetBlockType();
	int32 GetNumber();
	void SetNumberRepetition(int32 Number);
	int32 GetNumberRepetition();
	EDirection GetDirection();

};
