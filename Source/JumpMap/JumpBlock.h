// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBlock.h"
#include "JumpBlock.generated.h"

/**
 * 
 */
UCLASS()
class JUMPMAP_API AJumpBlock : public ABaseBlock
{
	GENERATED_BODY()

public:
	AJumpBlock();

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OSverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void PostInitializeComponents() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Speed;

	UPROPERTY(EditAnywhere)
	float Roatation;

	bool once = false;
};
