// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Aplastador.generated.h"

class APlataforma;
class AEstructura;
class AMuro;

UCLASS()
class NAVESLAB01USFX2026RA_API AAplastador : public AActor
{
	GENERATED_BODY()

public:
	TArray<AEstructura*> Plataformas;
	TArray<AEstructura*> Muros;

protected:
	virtual void BeginPlay() override;

public:	
	AAplastador();
	virtual void Tick(float DeltaTime) override;

};
