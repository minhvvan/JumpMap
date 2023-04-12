// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseBlock.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ABaseBlock::ABaseBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollsionMesh = CreateDefaultSubobject<UBoxComponent>(TEXT("COLLISION"));
	CollsionMesh->SetCollisionProfileName(TEXT("StepOn"));
	SetRootComponent(CollsionMesh);

	CollsionMesh->SetBoxExtent(FVector(100.f, 100.f, 30.f));
	//CollsionMesh->SetRelativeTransform(Mesh->GetRelativeTransform());

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	Mesh->SetupAttachment(RootComponent);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ARROW"));
	Arrow->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABaseBlock::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseBlock::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

