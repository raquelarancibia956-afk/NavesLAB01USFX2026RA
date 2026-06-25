// Fill out your copyright notice in the Description page of Project Settings.


#include "Corriendo.h"
#include "Moviendose.h"
#include "Quieto.h"
#include "NavesLAB01USFX2026RAPawn.h"


void ACorriendo::Disparar(float forwardValue, float rightValue)
{
	//
}

void ACorriendo::Moverse(float forwardValue, float rightValue, float bCorrer, float DeltaTime)
{
	if (forwardValue == 0 && rightValue == 0) {
		AEstado* estadoNuevo = GetWorld()->SpawnActor<AQuieto>(AQuieto::StaticClass());
		estadoNuevo->Jugador = Jugador;
		Jugador->CambiarEstado(estadoNuevo);
		return;
	}

	if (bCorrer == 0) {
		AEstado* estadoNuevo = GetWorld()->SpawnActor<AMoviendose>(AMoviendose::StaticClass());
		estadoNuevo->Jugador = Jugador;
		Jugador->CambiarEstado(estadoNuevo);
		return;
	}
	
	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(forwardValue, rightValue, 0.f).GetClampedToMaxSize(1.0f);
	float multiplicador = 3;
	// Calculate  movement
	const FVector Movement = MoveDirection * Jugador->MoveSpeed * multiplicador * DeltaTime;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		Jugador->GetRootComponent()->MoveComponent(Movement, NewRotation, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			Jugador->GetRootComponent()->MoveComponent(Deflection, NewRotation, true);
		}
	}
}



