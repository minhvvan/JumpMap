// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBlock.h"
#include "DropBlock.generated.h"

/**
 * 
 */
UCLASS()
class JUMPMAP_API ADropBlock : public ABaseBlock
{
	GENERATED_BODY()
	
public:
	ADropBlock();
	
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OSverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	virtual void PostInitializeComponents() override;

	UPROPERTY(EditAnywhere)
	float WaitTime;
};
