// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FabricaAEnemigo.generated.h"

class AEnemigo;

UCLASS()
class NAVESLAB01USFX2026RA_API AFabricaAEnemigo : public AActor
{
	GENERATED_BODY()
	

public:	
	AFabricaAEnemigo();
	virtual AEnemigo* CrearEnemigoFuerte(FVector posicion);
	virtual AEnemigo* CrearEnemigoDebil(FVector posicion);

};
