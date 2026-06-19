// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FabricaMEnemigo.generated.h"

class AEnemigo;

UCLASS()
class NAVESLAB01USFX2026RA_API AFabricaMEnemigo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricaMEnemigo();
	virtual AEnemigo* FabricarEnemigo(FVector posicion);

};
