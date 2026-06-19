// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavesLAB01USFX2026RAGameMode.h"
#include "FabricaMAcuatico.h"
#include "FabricaMEnemigo.h"
#include "FabricaMTerrestre.h"
#include "Director.h"
#include "FabricaMPlataforma.h"
#include "FabricaMMuro.h"
#include "Aplastador.h"
#include "NavesLAB01USFX2026RAPawn.h"

ANavesLAB01USFX2026RAGameMode::ANavesLAB01USFX2026RAGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ANavesLAB01USFX2026RAPawn::StaticClass();
}

void ANavesLAB01USFX2026RAGameMode::BeginPlay()
{
	AFabricaMEnemigo* fabrica = GetWorld()->SpawnActor<AFabricaMTerrestre>(AFabricaMTerrestre::StaticClass());
	Enemigo1 = fabrica->FabricarEnemigo(FVector(0, 0, 214.f));

	fabrica = GetWorld()->SpawnActor<AFabricaMAcuatico>(AFabricaMAcuatico::StaticClass());
	Enemigo2 = fabrica->FabricarEnemigo(FVector(-500, 0, 214.f));

	Aplastador1 = GetWorld()->SpawnActor<AAplastador>(FVector::ZeroVector, FRotator::ZeroRotator);


	ADirector* director = GetWorld()->SpawnActor<ADirector>(ADirector::StaticClass());
	AFabricaMPlataforma* builderPlataforma = GetWorld()->SpawnActor<AFabricaMPlataforma>(AFabricaMPlataforma::StaticClass());
	AFabricaMMuro* builderMuro = GetWorld()->SpawnActor<AFabricaMMuro>(AFabricaMMuro::StaticClass());

	director->SetBuilder(builderPlataforma);
	director->SetObjeto(Aplastador1);
	director->AplastadorSimple(FVector(600, 400, 214.f));

	director->SetBuilder(builderMuro);
	director->SetObjeto(Aplastador1);
	director->AplastadorSimple(FVector(600, 400, 214.f));

	
	
}

