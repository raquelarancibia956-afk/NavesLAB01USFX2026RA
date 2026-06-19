// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAcuatico.generated.h"

/**
 * 
 */
UCLASS()
class NAVESLAB01USFX2026RA_API AEnemigoAcuatico : public AEnemigo
{
	GENERATED_BODY()

public:
	FVector RangoMovimiento;


protected:
	virtual void BeginPlay() override;

public:
	AEnemigoAcuatico();
	virtual void Tick(float DeltaTime) override;
	virtual void Mover(float DeltaTime) override;
	
};
