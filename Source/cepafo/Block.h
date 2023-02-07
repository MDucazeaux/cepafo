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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "BlockType == EBType::EN", EditConditionHides), Category = "Block")
		int32 NumberRepetition = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "BlockType == EBType::ENumber", EditConditionHides), Category = "Block")
		int32 Numbre = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "BlockType == EBType::EArrow", EditConditionHides), Category = "Block")
		EDirection Direction = EDirection::ENull;
	
	bool DoOnce = true;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Block")
		 class USphereComponent* SphereComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool InSequence = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool InBlockN = false;
	
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "BlockType == EBType::ESequence", EditConditionHides), Category = "Block")
		TArray<ABlock*> Blocks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "BlockType == EBType::EN", EditConditionHides), Category = "Block")
		TArray<ABlock*> BlockInN;


	
	UFUNCTION(BlueprintCallable, Category = "Block")
		EBType GetBlockType();
	UFUNCTION(BlueprintCallable, Category = "Block")
		int32 GetNumber();
	
	void SetNumberRepetition(int32 Number);
	UFUNCTION(BlueprintCallable, Category = "Block")
		int32 GetNumberRepetition();
	UFUNCTION(BlueprintCallable, Category = "Block")
		EDirection GetDirection();

};
