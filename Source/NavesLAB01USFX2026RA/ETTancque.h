// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemigoTerrestre.h"
#include "ETTancque.generated.h"

UCLASS()
class NAVESLAB01USFX2026RA_API AETTancque : public AEnemigoTerrestre
{
	GENERATED_BODY()
public:
	AETTancque();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;

};
