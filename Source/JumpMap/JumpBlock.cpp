// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpBlock.h"
#include "Components/BoxComponent.h"
#include "JumpMapCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/ArrowComponent.h"
#include "Engine/DecalActor.h"
#include "Engine/StreamableManager.h"

AJumpBlock::AJumpBlock()
{
	Speed = 3000.f;
	Roatation = 90.f;
}

void AJumpBlock::OnOverlapBegin(UPrimitiveComponent* OSverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		auto Dir = Arrow->GetForwardVector() * Speed;
		auto Character = Cast<AJumpMapCharacter>(OtherActor);
		auto Movement = Cast<UCharacterMovementComponent>(Character->GetMovementComponent());
		Movement->AddImpulse(Dir, true);

		if (!once)
		{
			Arrow->SetRelativeRotation(FRotator(Roatation, 0.f, 0.f).Quaternion());
			once = true;
		}
	}
}

void AJumpBlock::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	CollsionMesh->OnComponentBeginOverlap.AddDynamic(this, &AJumpBlock::OnOverlapBegin);
}
