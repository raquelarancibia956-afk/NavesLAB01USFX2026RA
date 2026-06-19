// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaMAcuatico.h"
#include "EnemigoAcuatico.h"

AEnemigo* AFabricaMAcuatico::FabricarEnemigo(FVector posicion)
{
	return GetWorld()->SpawnActor<AEnemigoAcuatico>(posicion, FRotator::ZeroRotator);
}
