// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FabricaMEstructura.generated.h"

class AEstructura;

UCLASS()
class NAVESLAB01USFX2026RA_API AFabricaMEstructura : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricaMEstructura();
	virtual AEstructura* Fabricar()	PURE_VIRTUAL(&AFabricaMEstructura::Fabricar, return nullptr; );

	virtual void InicializarEstructura();

	virtual void SetPosicion(FVector posicion);
	virtual void SetTamanio(FVector tamanio);
	//virtual void SetCantidad(int cantidad);
};
