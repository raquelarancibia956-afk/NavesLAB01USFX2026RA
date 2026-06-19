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

void AFabricaMMuro::SetAlto(float alto)
{
	FVector tamanioOriginal = Muro->GetActorScale3D();
	Muro->SetActorScale3D(FVector(tamanioOriginal.X, tamanioOriginal.Y, alto));
}

AEstructura* AFabricaMMuro::Fabricar()
{
	return Muro;
}
