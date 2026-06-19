// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Director.generated.h"

class AFabricaMEstructura;
class AAplastador;

UCLASS()
class NAVESLAB01USFX2026RA_API ADirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADirector();

	AFabricaMEstructura* Builder;
	AAplastador* Aplastador;

	virtual void SetBuilder(AFabricaMEstructura* builder);
	virtual void SetObjeto(AAplastador* objeto);
	virtual AAplastador* AplastadorSimple(FVector posicion);



};
