// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Estado.h"
#include "Disparando.generated.h"

/**
 * 
 */
UCLASS()
class NAVESLAB01USFX2026RA_API ADisparando : public AEstado
{
	GENERATED_BODY()

public:
	virtual void Disparar(float forwardValue, float rightValue) override;
	virtual void Moverse(float forwardValue, float rightValue, float bCorrer, float DetlaTime) override;
	
};
