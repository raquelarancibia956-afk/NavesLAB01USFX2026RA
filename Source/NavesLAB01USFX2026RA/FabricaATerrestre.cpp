// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaATerrestre.h"
#include "ETBlindado.h"
#include "ETTancque.h"

void AFabricaATerrestre::CrearEnemigoFuerte(FVector posicion)
{
    return GetWorld()->SpawnActor<AETBlindado>(posicion, FRotator::ZeroRotator);
}

void AFabricaATerrestre::CrearEnemigoDebil(FVector posicion)
{
    return GetWorld()->SpawnActor<AETTancque>(posicion, FRotator::ZeroRotator);
}