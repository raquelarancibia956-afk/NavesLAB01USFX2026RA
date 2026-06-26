// Fill out your copyright notice in the Description page of Project Settings.


#include "EDanio.h"
#include "NavesLAB01USFX2026RAProjectile.h"

void AEDanio::AumentarFuncion()
{
	Super::AumentarFuncion();

	ANavesLAB01USFX2026RAProjectile* proyectil = Cast<ANavesLAB01USFX2026RAProjectile>(Decorador);

}
