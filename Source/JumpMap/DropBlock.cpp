// Fill out your copyright notice in the Description page of Project Settings.


#include "DropBlock.h"
#include "Components/BoxComponent.h"

ADropBlock::ADropBlock()
{
	WaitTime = 1.f;
}

void ADropBlock::OnOverlapBegin(UPrimitiveComponent* OSverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	FTimerHandle WaitHandle;
	GetWorld()->GetTimerManager().SetTimer(WaitHandle, FTimerDelegate::CreateLambda([this]()
		{
			UE_LOG(LogTemp, Warning, TEXT("ADropBlock::overlap"));

			Mesh->SetSimulatePhysics(true);
			CollsionMesh->SetCollisionProfileName(TEXT("StepOn"));

		}), WaitTime, false);
}

void ADropBlock::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	FTimerHandle WaitHandle;
	GetWorld()->GetTimerManager().SetTimer(WaitHandle, FTimerDelegate::CreateLambda([this]()
		{
			UE_LOG(LogTemp, Warning, TEXT("ADropBlock::overlap"));

			Mesh->SetSimulatePhysics(true);
			CollsionMesh->SetCollisionProfileName(TEXT("StepOn"));

		}), WaitTime, false);
}

void ADropBlock::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	//CollsionMesh->OnComponentBeginOverlap.AddDynamic(this, &ADropBlock::OnOverlapBegin);
	CollsionMesh->OnComponentHit.AddDynamic(this, &ADropBlock::OnHit);
}
