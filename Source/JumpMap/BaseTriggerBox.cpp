// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTriggerBox.h"
#include "ShootingBall.h"

ABaseTriggerBox::ABaseTriggerBox()
{
}

void ABaseTriggerBox::BeginPlay()
{
}

void ABaseTriggerBox::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	OnActorBeginOverlap.AddDynamic(this, &ABaseTriggerBox::Event);
}

void ABaseTriggerBox::Event(AActor* overlappedActor, AActor* otherActor)
{
	if (!ShootingBall.IsNull() && ShootingBall.IsValid())
	{
		ShootingBall->Shoot();
	}
}
