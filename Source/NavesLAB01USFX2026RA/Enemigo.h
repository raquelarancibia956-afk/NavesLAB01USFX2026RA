// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.generated.h"

UCLASS()
class NAVESLAB01USFX2026RA_API AEnemigo : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AEnemigo();
	int Vida;
	float Velocidad;
	UPROPERTY()
	UStaticMeshComponent* Malla;
	FVector Direccion;
	FVector DireccionDisparo;
	FVector PosicionInicial;
	float TiempoEntreDisparos;
	float VelocidadDisparo;
	bool PuedeDisparar;
	int DanioDisparo;
	FTimerHandle TimerHandle_Disparo;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetMalla(TCHAR* ruta);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Disparar();
	virtual void Mover(float DeltaTime);
	virtual void CambiarPuedeDisparar();
	virtual void RecibirDanio(int danio);

};
