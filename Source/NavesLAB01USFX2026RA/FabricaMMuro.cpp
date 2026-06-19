// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaMMuro.h"
#include "Muro.h"

void AFabricaMMuro::InicializarEstructura()
{
	Muro = GetWorld()->SpawnActor<AMuro>(FVector(0, 0, 0), FRotator::ZeroRotator);
}

void AFabricaMMuro::SetPosicion(FVector posicion)
{
	Muro->SetActorLocation(posicion);
}

void AFabricaMMuro::SetTamanio(FVector tamanio)
{
	Muro->SetActorScale3D(tamanio);
}

AEstructura* AFabricaMMuro::Fabricar()
{
	return Muro;
}
