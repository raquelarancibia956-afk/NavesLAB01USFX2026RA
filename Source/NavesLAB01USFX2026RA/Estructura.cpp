// Fill out your copyright notice in the Description page of Project Settings.


#include "Estructura.h"

// Sets default values
AEstructura::AEstructura()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla"));
	Malla->SetupAttachment(RootComponent);
	RootComponent = Malla;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (Mesh.Succeeded())
	{
		Malla->SetStaticMesh(Mesh.Object);
	}
}

// Called when the game starts or when spawned
void AEstructura::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstructura::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

