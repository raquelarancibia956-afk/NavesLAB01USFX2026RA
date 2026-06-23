// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaAAcuatico.h"
#include "EABarco.h"
#include "EALancha.h"

void AFabricaAAcuatico::CrearEnemigoFuerte(FVector posicion)
{
    return GetWorld()->SpawnActor<AEABarco>(posicion, FRotator::ZeroRotator);
}

void AFabricaAAcuatico::CrearEnemigoDebil(FVector posicion)
{
    return GetWorld()->SpawnActor<AEALancha>(posicion, FRotator::ZeroRotator);
}