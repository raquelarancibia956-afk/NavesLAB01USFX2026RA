// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereo.h"
#include "NavesLAB01USFX2026RAPawn.h"

AEnemigoAereo::AEnemigoAereo()
{
	Jugador = nullptr;
	SetMalla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe'"));
	PuedeDisparar = true;
	TiempoEntreDisparos = 1.0f;
}

void AEnemigoAereo::BeginPlay()
{
	ANavesLAB01USFX2026RAPawn* JugadorTemp = Cast<ANavesLAB01USFX2026RAPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (JugadorTemp != nullptr)
	{
		Jugador = JugadorTemp;
	}
}

void AEnemigoAereo::Tick(float DeltaTime)
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
