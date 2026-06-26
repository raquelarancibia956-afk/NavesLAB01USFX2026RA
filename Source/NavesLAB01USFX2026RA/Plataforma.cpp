// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"

APlataforma::APlataforma()
{
	SetActorScale3D(FVector(4.0f, 4.0f, 0.5f));
	Rango = FVector(0, 0, 500);
	Velocidad = 250;
	Direccion = FVector(0, 0, 1);
}

void APlataforma::Tick(float DeltaTime)
{
	if (FMath::Abs(GetActorLocation().Z-PosicionInicial.Z)>Rango.Z || GetActorLocation().Z<PosicionInicial.Z) {
		Direccion = -Direccion;

	}
	FVector desplazamiento = Velocidad * Direccion * DeltaTime;
	AddActorWorldOffset(desplazamiento, false);

}
