// Fill out your copyright notice in the Description page of Project Settings.


#include "Moviendose.h"
#include "Corriendo.h"
#include "Disparando.h"
#include "Quieto.h"
#include "NavesLAB01USFX2026RAPawn.h"
#include "Kismet/GameplayStatics.h"
#include "NavesLAB01USFX2026RAProjectile.h"


void AMoviendose::Disparar(float forwardValue, float rightValue)
{
	if (forwardValue == 1 || rightValue == 1) {
		AEstado* estadoNuevo = GetWorld()->SpawnActor<ADisparando>(ADisparando::StaticClass());
		Jugador->CambiarEstado(estadoNuevo);
		estadoNuevo->Jugador = Jugador;
		return;
	}

	
}

void AMoviendose::Moverse(float forwardValue, float rightValue, float bCorrer, float DeltaTime)
{
	if (forwardValue == 0 && rightValue == 0) {
		AEstado* estadoNuevo = GetWorld()->SpawnActor<AQuieto>(AQuieto::StaticClass());
		Jugador->CambiarEstado(estadoNuevo);
		estadoNuevo->Jugador = Jugador;
		return;
	}

	if (bCorrer == 1) {
		AEstado* estadoNuevo = GetWorld()->SpawnActor<ACorriendo>(ACorriendo::StaticClass());
		Jugador->CambiarEstado(estadoNuevo);
		estadoNuevo->Jugador = Jugador;
		return;
	}

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(forwardValue, rightValue, 0.f).GetClampedToMaxSize(1.0f);
	float multiplicador = 1;
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
