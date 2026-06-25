// Fill out your copyright notice in the Description page of Project Settings.


#include "Quieto.h"
#include "Corriendo.h"
#include "Disparando.h"
#include "Moviendose.h"
#include "NavesLAB01USFX2026RAPawn.h"

void AQuieto::Disparar(float forwardValue, float rightValue)
{
	if (forwardValue == 1 || rightValue == 1) {
		AEstado* estadoNuevo = GetWorld()->SpawnActor<ADisparando>(ADisparando::StaticClass());
		estadoNuevo->Jugador = Jugador;
		Jugador->CambiarEstado(estadoNuevo);
	}
}

void AQuieto::Moverse(float forwardValue, float rightValue, float bCorrer, float DetlaTime)
{
	if (forwardValue == 1 || rightValue == 1) {
		AEstado* estadoNuevo = GetWorld()->SpawnActor<AMoviendose>(AMoviendose::StaticClass());
		estadoNuevo->Jugador = Jugador;
		Jugador->CambiarEstado(estadoNuevo);
	}
}


