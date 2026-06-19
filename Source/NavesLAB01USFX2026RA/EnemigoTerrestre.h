// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoTerrestre.generated.h"

class ANavesLAB01USFX2026RAPawn;

UCLASS()
class NAVESLAB01USFX2026RA_API AEnemigoTerrestre : public AEnemigo
{
	GENERATED_BODY()

	ANavesLAB01USFX2026RAPawn* Jugador;
	AEnemigoTerrestre();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
