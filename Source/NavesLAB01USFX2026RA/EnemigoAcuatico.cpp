// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAcuatico.h"

AEnemigoAcuatico::AEnemigoAcuatico()
{
	SetMalla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	RangoMovimiento = FVector(1000.0f, 1000.0f, 1000.0f);
	Direccion = FVector(1.0f, 0.0f, 0.0f);
	TiempoEntreDisparos = 0.5f;
	Velocidad = 50.0f;
	DireccionDisparo = FVector(0.0f, -1.0f, 0.0f);

}

void AEnemigoAcuatico::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
}


void AEnemigoAcuatico::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
	Disparar();
}

void AEnemigoAcuatico::Mover(float DeltaTime)
{
	FVector distancia = GetActorLocation() - PosicionInicial;
	if (FMath::Abs(distancia.X) > RangoMovimiento.X)
	{
		Direccion = -Direccion;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Cambio de dirección en X"));
	}
	//Super::Mover(DeltaTime);
	FVector desplazamiento = Direccion * Velocidad * DeltaTime;
	AddActorLocalOffset(desplazamiento, true);
}
