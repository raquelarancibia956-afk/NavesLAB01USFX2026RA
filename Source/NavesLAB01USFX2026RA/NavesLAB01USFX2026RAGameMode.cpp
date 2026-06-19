// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavesLAB01USFX2026RAGameMode.h"
#include "FabricaMAcuatico.h"
#include "FabricaMEnemigo.h"
#include "FabricaMTerrestre.h"
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
	
}

