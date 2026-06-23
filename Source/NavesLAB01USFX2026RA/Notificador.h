// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Notificador.generated.h"

class ISuscriptor;
UCLASS()
class NAVESLAB01USFX2026RA_API ANotificador : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANotificador();
	TArray<ISuscriptor*> Suscriptores;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Inscribir(ISuscriptor* suscriptor);
	virtual void Desuscribir(ISuscriptor* suscriptor);
	virtual void Notificar();
	
};
