// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaMPlataforma.h"
#include "Plataforma.h"

AEstructura* AFabricaMPlataforma::Fabricar()
{
	return GetWorld()->SpawnActor<APlataforma>(FVector(0, 0, 0), FRotator::ZeroRotator);
}
