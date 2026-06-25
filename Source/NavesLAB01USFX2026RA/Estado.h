// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estado.generated.h"

class ANavesLAB01USFX2026RAPawn;

UCLASS()
class NAVESLAB01USFX2026RA_API AEstado : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	ANavesLAB01USFX2026RAPawn* Jugador;

protected:
	virtual void BeginPlay() override;

public:
	AEstado();
	virtual void Disparar(float forwardValue, float rightValue) PURE_VIRTUAL(AEstado::Disparar);
	virtual void Moverse(float forwardValue, float rightValue, float bCorrer, float DeltaTime) PURE_VIRTUAL(AEstado::Moverse);
	virtual void Tick(float DeltaTime) override;

};
