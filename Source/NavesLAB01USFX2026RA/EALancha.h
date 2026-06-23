// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemigoAcuatico.h"
#include "EALancha.generated.h"

/**
 * 
 */
UCLASS()
class NAVESLAB01USFX2026RA_API AEALancha : public AEnemigoAcuatico
{
	GENERATED_BODY()
public:
	AEALancha();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;

};
