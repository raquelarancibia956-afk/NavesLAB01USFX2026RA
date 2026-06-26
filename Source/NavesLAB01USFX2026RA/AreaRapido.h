// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Area.h"
#include "AreaRapido.generated.h"

/**
 * 
 */
UCLASS()
class NAVESLAB01USFX2026RA_API AAreaRapido : public AArea
{
	GENERATED_BODY()
	
public:
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

};
