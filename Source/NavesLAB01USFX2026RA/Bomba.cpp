// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomba.h"
#include "NavesLAB01USFX2026RAProjectile.h"
#include "Notificador.h"

// Sets default values
ABomba::ABomba()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla"));
	Malla->SetupAttachment(RootComponent);
	RootComponent = Malla;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Forma(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
	if (Forma.Succeeded()) {
		Malla->SetStaticMesh(Forma.Object);
	}

	Resistencia = 300;

}

// Called when the game starts or when spawned
void ABomba::BeginPlay()
{
	Super::BeginPlay();
	Emisor = GetWorld()->SpawnActor<ANotificador>(ANotificador::StaticClass());
}

// Called every frame
void ABomba::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Resistencia <=0) {
		Emisor->Notificar();
		Destroy();
	}
}