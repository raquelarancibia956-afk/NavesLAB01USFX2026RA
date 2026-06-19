// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FabricaMEnemigo.h"
#include "FabricaMTerrestre.generated.h"

/**
 * 
 */
UCLASS()
class NAVESLAB01USFX2026RA_API AFabricaMTerrestre : public AFabricaMEnemigo
{
	GENERATED_BODY()

public:
	virtual AEnemigo* FabricarEnemigo(FVector posicion) override;
	
};
