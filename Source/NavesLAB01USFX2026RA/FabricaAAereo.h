// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FabricaAEnemigo.h"
#include "FabricaAAereo.generated.h"

/**
 * 
 */
UCLASS()
class NAVESLAB01USFX2026RA_API AFabricaAAereo : public AFabricaAEnemigo
{
	GENERATED_BODY()
	
public:
	AFabricaAAereo();
	virtual AEnemigo* CrearEnemigoFuerte(FVector posicion) override;
	virtual AEnemigo* CrearEnemigoDebil(FVector posicion) override;
	
};
