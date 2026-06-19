// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estructura.generated.h"

UCLASS()
class NAVESLAB01USFX2026RA_API AEstructura : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstructura();

	UPROPERTY()
	UStaticMeshComponent* Malla;
	FVector PosicionInicial;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
