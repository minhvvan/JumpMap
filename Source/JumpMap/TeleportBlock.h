// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBlock.h"
#include "TeleportBlock.generated.h"

/**
 * 
 */
UCLASS()
class JUMPMAP_API ATeleportBlock : public ABaseBlock
{
	GENERATED_BODY()
	
public:
	ATeleportBlock();

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OSverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void PostInitializeComponents() override;

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<ABaseBlock> Destination;

	UPROPERTY(EditAnywhere)
	float WaitTime;

	UPROPERTY(EditAnywhere)
	class UParticleSystem* FX;

	UPROPERTY(EditAnywhere)
	class UParticleSystemComponent* FXSys;
};
