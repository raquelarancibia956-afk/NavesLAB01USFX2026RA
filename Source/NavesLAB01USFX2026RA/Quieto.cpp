// Fill out your copyright notice in the Description page of Project Settings.


#include "Quieto.h"
#include "Corriendo.h"
#include "Moviendose.h"
#include "Kismet/GameplayStatics.h"
#include "NavesLAB01USFX2026RAProjectile.h"
#include "NavesLAB01USFX2026RAPawn.h"

void AQuieto::Disparar(float forwardValue, float rightValue)
{
	const FVector FireDirection = FVector(forwardValue, rightValue, 0.f);
	// If it's ok to fire again
	if (Jugador->bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = Jugador->GetActorLocation() + FireRotation.RotateVector(Jugador->GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				ANavesLAB01USFX2026RAProjectile* bala;
				bala = World->SpawnActor<ANavesLAB01USFX2026RAProjectile>(SpawnLocation, FireRotation);
				bala->SetDanio(Jugador->Danio);
				Jugador->Proyectiles.Add(bala);
			}

			Jugador->bCanFire = false;
			World->GetTimerManager().SetTimer(Jugador->TimerHandle_ShotTimerExpired, Jugador, &ANavesLAB01USFX2026RAPawn::ShotTimerExpired, Jugador->FireRate);

			// try and play the sound if specified
			if (Jugador->FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(Jugador, Jugador->FireSound, Jugador->GetActorLocation());
			}

			Jugador->bCanFire = false;
		}
	}
}

void AQuieto::Moverse(float forwardValue, float rightValue, float bCorrer, float DetlaTime)
{
	if (FMath::Abs(forwardValue) == 1 || FMath::Abs(rightValue) == 1) {
		AEstado* estadoNuevo = GetWorld()->SpawnActor<AMoviendose>(AMoviendose::StaticClass());
		estadoNuevo->Jugador = Jugador;
		Jugador->CambiarEstado(estadoNuevo);
	}
}


