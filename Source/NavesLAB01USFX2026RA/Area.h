// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Decorador.h"
#include "Area.generated.h"


UCLASS()
class NAVESLAB01USFX2026RA_API AArea : public AActor
{
	GENERATED_BODY()
	
public:
	UStaticMeshComponent* Malla;

protected:
	virtual void BeginPlay() override;

public:	
	AArea();
	UFUNCTION()
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
