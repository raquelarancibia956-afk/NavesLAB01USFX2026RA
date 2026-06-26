// Fill out your copyright notice in the Description page of Project Settings.


#include "Area.h"
#include "NavesLAB01USFX2026RAProjectile.h"
#include "Decorador.h"
#include "NavesLAB01USFX2026RAPawn.h"

// Sets default values
AArea::AArea()
{
	PrimaryActorTick.bCanEverTick = true;
	Malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla"));
	Malla->SetupAttachment(RootComponent);
	RootComponent = Malla;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Forma(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (Forma.Succeeded()) {
		Malla->SetStaticMesh(Forma.Object);
	}

	Malla->SetWorldScale3D(FVector(4, 0.2, 4));

	Malla->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Malla->SetCollisionObjectType(ECC_EngineTraceChannel4);
	Malla->SetCollisionResponseToAllChannels(ECR_Overlap);

}

// Called when the game starts or when spawned
void AArea::BeginPlay()
{
	Super::BeginPlay();
	
}

void AArea::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}


