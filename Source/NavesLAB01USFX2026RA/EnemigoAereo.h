// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAereo.generated.h"

class ANavesLAB01USFX2026RAPawn;

UCLASS()
class NAVESLAB01USFX2026RA_API AEnemigoAereo : public AEnemigo
{
	GENERATED_BODY()
public:

	ANavesLAB01USFX2026RAPawn* Jugador;
	AEnemigoAereo();
protected:
	virtual void BeginPlay() override;

public:
	AEnemigoAereo();
	virtual void Tick(float DeltaTime) override;
};
