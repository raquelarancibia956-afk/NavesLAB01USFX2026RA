// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Facade.generated.h"

class AEnemigo;

UCLASS()
class NAVESLAB01USFX2026RA_API AFacade : public AActor
{
	GENERATED_BODY()
	
public:
	TArray<AEnemigo*> Enemigos;
	AEnemigo* Cerebro;

protected:
	virtual void BeginPlay() override;

public:	
	AFacade();
	virtual void Tick(float DeltaTime) override;
	virtual void CrearEnemigoAcuatico(int cantidad, FVector posicion = FVector::ZeroVector);
	virtual void CrearEnemigoTerrestre(int cantidad, FVector posicion = FVector::ZeroVector);
	virtual void DestruirEnemigos();

};
