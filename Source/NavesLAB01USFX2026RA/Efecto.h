// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Efecto.generated.h"

class ANavesLAB01USFX2026RAPawn;

UINTERFACE(MinimalAPI)
class UEfecto : public UInterface
{
	GENERATED_BODY()
};

class NAVESLAB01USFX2026RA_API IEfecto
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void AplicarEfecto(ANavesLAB01USFX2026RAPawn* objetivo);
};
