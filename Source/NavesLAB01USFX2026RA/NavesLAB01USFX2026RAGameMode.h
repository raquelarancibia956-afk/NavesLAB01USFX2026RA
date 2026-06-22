// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NavesLAB01USFX2026RAGameMode.generated.h"

class AEnemigo;
class AAplastador;

UCLASS(MinimalAPI)
class ANavesLAB01USFX2026RAGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANavesLAB01USFX2026RAGameMode();
	virtual void BeginPlay() override;

	AEnemigo* Enemigo1;
	AEnemigo* Enemigo2;
	AAplastador* Aplastador1;
	

};



