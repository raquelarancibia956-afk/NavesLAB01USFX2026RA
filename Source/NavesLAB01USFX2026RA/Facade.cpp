// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade.h"
#include "FabricaMAcuatico.h"
#include "EnemigoAcuatico.h"
#include "FabricaMTerrestre.h"
#include "EnemigoTerrestre.h"

// Sets default values
AFacade::AFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFacade::BeginPlay()
{
	Super::BeginPlay();
	UWorld* World = GetWorld();
	
}

// Called every frame
void AFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFacade::CrearEnemigoAcuatico(int cantidad, FVector posicion)
{
	AFabricaMEnemigo* fabrica = GetWorld()->SpawnActor<AFabricaMAcuatico>(AFabricaMAcuatico::StaticClass());
	posicion.Z = 214.f;
	for (int i = 0; i < cantidad; i++) {
		AEnemigo* enemigo = fabrica->FabricarEnemigo(posicion + FVector(100, 0, 0) * i);
		Enemigos.Add(enemigo);
	}
}

void AFacade::CrearEnemigoTerrestre(int cantidad, FVector posicion)
{
	AFabricaMEnemigo* fabrica = GetWorld()->SpawnActor<AFabricaMTerrestre>(AFabricaMTerrestre::StaticClass());
	posicion.Z = 214.f;
	for (int i = 0; i < cantidad; i++) {
		AEnemigo* enemigo = fabrica->FabricarEnemigo(posicion + FVector(160, 0, 0) * i);
		Enemigos.Add(enemigo);
	}
}
