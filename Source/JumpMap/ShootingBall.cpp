// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingBall.h"
#include "Components/SphereComponent.h"
#include "Components/ArrowComponent.h"
#include "BaseTriggerBox.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "JumpMapCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AShootingBall::AShootingBall()
{
	Radius = 100.f;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollsionMesh = CreateDefaultSubobject<USphereComponent>(TEXT("SPHERE"));
	SetRootComponent(CollsionMesh);
	CollsionMesh->InitSphereRadius(Radius);
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	Mesh->SetupAttachment(RootComponent);

	Arrow = CreateDefaultSubobject<UArrowComponent >(TEXT("ARROW"));
	Arrow->SetupAttachment(RootComponent);

	ProjetileMovement = CreateDefaultSubobject<UProjectileMovementComponent >(TEXT("PROJETILEMOVEMENT"));
	ProjetileMovement->SetUpdatedComponent(CollsionMesh);
	ProjetileMovement->InitialSpeed = 3000.0f;
	ProjetileMovement->MaxSpeed = 3000.0f;
	ProjetileMovement->bRotationFollowsVelocity = true;
	ProjetileMovement->bShouldBounce = true;
	ProjetileMovement->Bounciness = 0.3f;
	ProjetileMovement->ProjectileGravityScale = 0.0f;
}

// Called when the game starts or when spawned
void AShootingBall::BeginPlay()
{
	Super::BeginPlay();
}

void AShootingBall::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	CollsionMesh->OnComponentHit.AddDynamic(this, &AShootingBall::OnHit);
}

void AShootingBall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherActor != this && Cast<AJumpMapCharacter>(OtherActor))
	{
		auto Dir = Arrow->GetForwardVector() * ProjetileMovement->InitialSpeed;
		auto Character = Cast<AJumpMapCharacter>(OtherActor);
		auto Movement = Cast<UCharacterMovementComponent>(Character->GetMovementComponent());
		Movement->AddImpulse(Dir, true);
	}
}

void AShootingBall::Shoot()
{
	ProjetileMovement->SetActive(true);
}


