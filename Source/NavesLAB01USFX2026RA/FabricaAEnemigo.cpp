// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaAEnemigo.h"
#include "Enemigo.h"

// Sets default values
AFabricaAEnemigo::AFabricaAEnemigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


AEnemigo* AFabricaAEnemigo::CrearEnemigoFuerte(FVector posicion)
{
	return nullptr;	
}

AEnemigo* AFabricaAEnemigo::CrearEnemigoDebil(FVector posicion)
{
	return nullptr;	
}