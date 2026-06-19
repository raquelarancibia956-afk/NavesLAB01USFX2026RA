// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaMTerrestre.h"
#include "EnemigoTerrestre.h"

AEnemigo* AFabricaMTerrestre::FabricarEnemigo(FVector posicion)
{
	return GetWorld()->SpawnActor<AEnemigoTerrestre>(posicion, FRotator::ZeroRotator);
}
