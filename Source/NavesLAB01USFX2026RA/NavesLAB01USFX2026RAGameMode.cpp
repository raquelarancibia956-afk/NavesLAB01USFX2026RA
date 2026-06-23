// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavesLAB01USFX2026RAGameMode.h"
#include "FabricaMAcuatico.h"
#include "FabricaMEnemigo.h"
#include "FabricaMTerrestre.h"
#include "FabricaMPlataforma.h"
#include "Director.h"
#include "FabricaMMuro.h"
#include "Aplastador.h"
#include "Facade.h"
#include "FabricaAEnemigo.h"
#include "FabricaAAcuatico.h"
#include "FabricaAAereo.h"
#include "FabricaATerrestre.h"
#include "NavesLAB01USFX2026RAPawn.h"

ANavesLAB01USFX2026RAGameMode::ANavesLAB01USFX2026RAGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ANavesLAB01USFX2026RAPawn::StaticClass();
}

void ANavesLAB01USFX2026RAGameMode::BeginPlay()
{
	UWorld* World = GetWorld();
	if (!World) return;

	// Factory method
	Facade = World->SpawnActor<AFacade>(AFacade::StaticClass());
	Facade->CrearEnemigoAcuatico(5);
	Facade->CrearEnemigoTerrestre(4, FVector(-200, 600, 0));

	// Abstract Factory
	AFabricaAEnemigo* fabrica = World->SpawnActor<AFabricaATerrestre>(AFabricaATerrestre::StaticClass());
	Facade->SetFabricaAbstracta(fabrica);
	Facade->CrearDuo(FVector(400, -500, 214));


	// Builder
	Aplastador1 = World->SpawnActor<AAplastador>(FVector::ZeroVector, FRotator::ZeroRotator);

	ADirector* director = World->SpawnActor<ADirector>(ADirector::StaticClass());
	AFabricaMPlataforma* builderPlataforma = World->SpawnActor<AFabricaMPlataforma>(AFabricaMPlataforma::StaticClass());
	AFabricaMMuro* builderMuro = World->SpawnActor<AFabricaMMuro>(AFabricaMMuro::StaticClass());

	director->SetBuilder(builderPlataforma);
	director->SetObjeto(Aplastador1);
	director->AplastadorSimple(FVector(600, 400, 214.f));

	director->SetBuilder(builderMuro);
	director->SetObjeto(Aplastador1);
	director->AplastadorSimple(FVector(600, 400, 214.f));

	
	
}

