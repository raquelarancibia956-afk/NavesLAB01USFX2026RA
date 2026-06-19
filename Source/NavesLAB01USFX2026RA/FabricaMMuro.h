// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FabricaMEstructura.h"
#include "FabricaMMuro.generated.h"

class AEstructura;

UCLASS()
class NAVESLAB01USFX2026RA_API AFabricaMMuro : public AFabricaMEstructura
{
	GENERATED_BODY()
public:
	AEstructura* Muro;

	virtual void InicializarEstructura() override;
	virtual void SetPosicion(FVector posicion) override;
	virtual void SetTamanio(FVector tamanio) override;
	//virtual void SetCantidad(int cantidad) override;


	virtual AEstructura* Fabricar() override;

	
};
