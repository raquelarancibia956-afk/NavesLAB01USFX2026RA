// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Facade.generated.h"

UCLASS()
class NAVESLAB01USFX2026RA_API AFacade : public AActor
{
	GENERATED_BODY()
	
public:
	TArray<AActor*> Objetos;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	AFacade();
	virtual void CrearEnemigosAcuatico(int cantidad);
	virtual void CrearEnemigosTerrestre(int cantidad);


};
