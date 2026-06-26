// Fill out your copyright notice in the Description page of Project Settings.


#include "Velocidad.h"
#include "NavesLAB01USFX2026RAPawn.h"

// Sets default values
AVelocidad::AVelocidad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla"));
	Malla->SetupAttachment(RootComponent);
	RootComponent = Malla;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Forma(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	if (Forma.Succeeded()) {
		Malla->SetStaticMesh(Forma.Object);
	}
	Malla->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Malla->SetCollisionObjectType(ECC_EngineTraceChannel3);
	Malla->SetCollisionResponseToAllChannels(ECR_Overlap);

}

// Called when the game starts or when spawned
void AVelocidad::BeginPlay()
{
	Super::BeginPlay();
	Malla->OnComponentBeginOverlap.AddDynamic(this, &AVelocidad::OnBeginOverlap);
}

// Called every frame
void AVelocidad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AVelocidad::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ANavesLAB01USFX2026RAPawn* jugador = Cast<ANavesLAB01USFX2026RAPawn>(OtherActor);
	if (jugador) {
		jugador->SetEstrategia(this);
		
		SetActorHiddenInGame(true);
		SetActorEnableCollision(false);
	}
}

void AVelocidad::AplicarEfecto(ANavesLAB01USFX2026RAPawn* objetivo)
{
	Jugador = objetivo;
	Guardado = objetivo->MoveSpeed;
	objetivo->MoveSpeed = 3000;
	GetWorldTimerManager().SetTimer(Temporizador, this, &AVelocidad::RestablecerEfecto, 5, false);
}
void AVelocidad::RestablecerEfecto()
{
	Jugador->MoveSpeed = Guardado;
	Destroy();

}
