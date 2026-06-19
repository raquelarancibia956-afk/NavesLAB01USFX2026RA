// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade.h"
#include "EnemigoTerrestre.h"
#include "EnemigoAcuatico.h"
#include "FabricaMEnemigo.h"
#include "FabricaMAcuatico.h"
#include "FabricaMTerrestre.h"


// Sets default values
AFacade::AFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFacade::CrearEnemigosAcuatico(int cantidad)
{
	AFabricaMEnemigo* fabrica = GetWorld()->SpawnActor<AFabricaMAcuatico>(AFabricaMAcuatico::StaticClass());
	for (int i = 0; i < cantidad; i++) {
		AEnemigo* enemigo = fabrica->FabricarEnemigo(FVector(500 + 100 * i, 0, 214.f));
		Objetos.Add(enemigo);
	}
}
void AFacade::CrearEnemigosTerrestre(int cantidad)
{	
	AFabricaMEnemigo* fabrica = GetWorld()->SpawnActor<AFabricaMTerrestre>(AFabricaMTerrestre::StaticClass());
	for (int i = 0; i < cantidad; i++) {
		AEnemigo* enemigo = fabrica->FabricarEnemigo(FVector(-500, 0 + 200 + 200 * i, 214.f));
		Objetos.Add(enemigo);
	}
}

// Called when the game starts or when spawned
void AFacade::BeginPlay()
{
	Super::BeginPlay();
	
}


