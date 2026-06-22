// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo.h"
#include "Suscriptor.h"	
#include "NavesLAB01USFX2026RAProjectile.h"

// Sets default values
AEnemigo::AEnemigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla"));
	Malla->SetupAttachment(RootComponent);
	RootComponent = Malla;

	Vida = 100;	
	Velocidad = 100.0f;
	PuedeDisparar = true;
	DanioDisparo = 10;


}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemigo::SetMalla(TCHAR* ruta)
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(ruta);
	if (Mesh.Succeeded())
	{
		Malla->SetStaticMesh(Mesh.Object);
	}
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
	Disparar();

}

void AEnemigo::Disparar()
{
	if (PuedeDisparar)
	{
		FRotator RotacionDisparo = DireccionDisparo.Rotation();
		FVector PosicionDisparo = GetActorLocation() + RotacionDisparo.RotateVector(FVector(100.0f, 0.0f, 0.0f));

		UWorld* Mundo = GetWorld();
		if (Mundo != nullptr)
		{
			ANavesLAB01USFX2026RAProjectile* bala = Mundo->SpawnActor<ANavesLAB01USFX2026RAProjectile>(PosicionDisparo, RotacionDisparo);
			bala->SetDanio(DanioDisparo);
			PuedeDisparar = false;
			GetWorldTimerManager().SetTimer(TimerHandle_Disparo, this, &AEnemigo::CambiarPuedeDisparar, TiempoEntreDisparos, true);
		}
	}
}

void AEnemigo::Mover(float DeltaTime)
{
	FVector desplazamiento = Direccion * Velocidad * DeltaTime;
	AddActorLocalOffset(desplazamiento, true);

	
}

void AEnemigo::CambiarPuedeDisparar()
{
	PuedeDisparar = true;
}

void AEnemigo::RecibirDanio(int danio)
{
	Vida -= danio;
	if (Vida <= 0)
	{
		Destroy();
	}
}

void AEnemigo::AccionEspecial()
{
	Destroy();
}

