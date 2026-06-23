// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade.h"
#include "FabricaMAcuatico.h"
#include "EnemigoAcuatico.h"
#include "FabricaMTerrestre.h"
#include "EnemigoTerrestre.h"
#include "FabricaAEnemigo.h"
#include "Bomba.h"
#include "Notificador.h"

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
	Bomba = World->SpawnActor<ABomba>(FVector(-500, -700, 214), FRotator::ZeroRotator);
	
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
		Bomba->Emisor->Inscribir(enemigo);
		Enemigos.Add(enemigo);
	}
}

void AFacade::CrearEnemigoTerrestre(int cantidad, FVector posicion)
{
	AFabricaMEnemigo* fabrica = GetWorld()->SpawnActor<AFabricaMTerrestre>(AFabricaMTerrestre::StaticClass());
	posicion.Z = 214.f;
	for (int i = 0; i < cantidad; i++) {
		AEnemigo* enemigo = fabrica->FabricarEnemigo(posicion + FVector(160, 0, 0) * i);
		Bomba->Emisor->Inscribir(enemigo);
		Enemigos.Add(enemigo);
	}

}

void AFacade::CrearDuo(FVector posicion)
{
	AEnemigo* enemigoFuerte = FabricaAbstracta->CrearEnemigoFuerte(posicion);
	AEnemigo* enemigoDebil = FabricaAbstracta->CrearEnemigoDebil(posicion + FVector(150,150,0));
	Bomba->Emisor->Inscribir(enemigoFuerte);
	Bomba->Emisor->Inscribir(enemigoDebil);
	Enemigos.Add(enemigoFuerte);
	Enemigos.Add(enemigoDebil);
}

void AFacade::SetFabricaAbstracta(AFabricaAEnemigo* fabrica)
{
	FabricaAbstracta = fabrica;
}