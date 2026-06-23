// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FabricaAEnemigo.h"
#include "FabricaATerrestre.generated.h"

class AEnemigo;

/**
 * 
 */
UCLASS()
class NAVESLAB01USFX2026RA_API AFabricaATerrestre : public AFabricaAEnemigo
{
	GENERATED_BODY()

public:
	AFabricaATerrestre();
	virtual AEnemigo* CrearEnemigoFuerte(FVector posicion) override;
	virtual AEnemigo* CrearEnemigoDebil(FVector posicion) override;
	
};
