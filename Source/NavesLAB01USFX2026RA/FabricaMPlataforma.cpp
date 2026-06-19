// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaMPlataforma.h"
#include "Plataforma.h"

AEstructura* AFabricaMPlataforma::Fabricar()
{
	return Plataforma;
}

void AFabricaMPlataforma::InicializarEstructura()
{
	Plataforma = GetWorld()->SpawnActor<APlataforma>(FVector::ZeroVector, FRotator::ZeroRotator);
}

void AFabricaMPlataforma::SetPosicion(FVector posicion)
{
	Plataforma->SetActorLocation(posicion);
}

void AFabricaMPlataforma::SetTamanio(FVector tamanio)
{
	Plataforma->SetActorScale3D(tamanio);
}

