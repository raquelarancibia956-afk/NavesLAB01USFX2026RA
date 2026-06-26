// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Decorador.h"
#include "Envoltura.generated.h"


UCLASS()
class NAVESLAB01USFX2026RA_API AEnvoltura : public AActor, public IDecorador
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnvoltura();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	IDecorador* Decorador;
	virtual void AumentarFuncion() override;

};
