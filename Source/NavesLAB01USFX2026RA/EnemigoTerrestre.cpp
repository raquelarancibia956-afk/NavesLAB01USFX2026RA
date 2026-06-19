// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoTerrestre.h"
#include "NavesLAB01USFX2026RAPawn.h"

AEnemigoTerrestre::AEnemigoTerrestre()
{
	Jugador = nullptr;
	SetMalla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	PuedeDisparar = true;
	TiempoEntreDisparos = 1.0f;
}

void AEnemigoTerrestre::BeginPlay()
{
	Super::BeginPlay();
	ANavesLAB01USFX2026RAPawn* JugadorTemp = Cast<ANavesLAB01USFX2026RAPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (JugadorTemp != nullptr)
	{
		Jugador = JugadorTemp;
	}
}

void AEnemigoTerrestre::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Jugador != nullptr)
	{
		FVector DireccionJugador = Jugador->GetActorLocation() - GetActorLocation();
		DireccionJugador.Z = 0.0f;
		DireccionJugador.Normalize();
		Direccion = DireccionJugador;
		DireccionDisparo = DireccionJugador;
	}
	Mover(DeltaTime);
	Disparar();
}
