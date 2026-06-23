// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaAAereo.h"
#include "EAAvion.h"
#include "EADron.h"

AFabricaAAereo::AFabricaAAereo()
{
}

AEnemigo* AFabricaAAereo::CrearEnemigoFuerte(FVector posicion)
{
    return GetWorld()->SpawnActor<AEAAvion>(posicion, FRotator::ZeroRotator);
}

AEnemigo* AFabricaAAereo::CrearEnemigoDebil(FVector posicion)
{
    return GetWorld()->SpawnActor<AEADron>(posicion, FRotator::ZeroRotator);
}