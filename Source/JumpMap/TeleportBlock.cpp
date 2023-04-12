// Fill out your copyright notice in the Description page of Project Settings.


#include "TeleportBlock.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Containers/UnrealString.h"
#include "Particles/ParticleSystem.h"
#include "Engine/Classes/Particles/ParticleSystemComponent.h"
#include "JumpMapCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

ATeleportBlock::ATeleportBlock()
{
	WaitTime = 1.f;

	static ConstructorHelpers::FObjectFinder<UParticleSystem> PS(TEXT("/Script/Engine.ParticleSystem'/Game/StarterContent/Particles/Realistic_Starter_VFX_Pack_Vol2/Particles/Sparks/P_Sparks_B.P_Sparks_B'"));
	if (PS.Succeeded())
	{
		FX = PS.Object;
	}

	FXSys = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("CASCADE"));
	FXSys->SetupAttachment(RootComponent);
	FXSys->bAutoActivate = false;
	FXSys->SetTemplate(FX);
}

void ATeleportBlock::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!Destination.IsNull())
	{
		if (OtherActor && OtherActor != this)
		{
			FXSys->ToggleActive();
			auto Movement = Cast<AJumpMapCharacter>(OtherActor)->GetCharacterMovement();
			Movement->SetMovementMode(EMovementMode::MOVE_None);

			FTimerHandle WaitHandle;
			GetWorld()->GetTimerManager().SetTimer(WaitHandle, FTimerDelegate::CreateLambda([this, OtherActor, Movement]()
				{
					auto dest = Destination->GetActorLocation() + FVector(0.f, 0.f, 10.f);
					OtherActor->TeleportTo(dest, FRotator::ZeroRotator, false, true);
					Movement->SetMovementMode(EMovementMode::MOVE_Walking);

					FXSys->SetActive(false);
				}), WaitTime, false);
		}
	}
}

void ATeleportBlock::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	CollsionMesh->OnComponentBeginOverlap.AddDynamic(this, &ATeleportBlock::OnOverlapBegin);
}

void ATeleportBlock::BeginPlay()
{

}
