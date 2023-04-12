// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "BaseTriggerBox.generated.h"


/**
 * 
 */
UCLASS()
class JUMPMAP_API ABaseTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
public:
	ABaseTriggerBox();

	virtual void BeginPlay();
	virtual void PostInitializeComponents() override;

	UFUNCTION()
	void Event(class AActor* overlappedActor, class AActor* otherActor);

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<class AShootingBall> ShootingBall;

};
