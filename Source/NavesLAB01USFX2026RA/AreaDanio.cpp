// Fill out your copyright notice in the Description page of Project Settings.


#include "AreaDanio.h"
#include "EDanio.h"
#include "Decorador.h"

void AAreaDanio::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IDecorador* proyectil = Cast<IDecorador>(OtherActor);
	if (proyectil == nullptr) return;
	AEnvoltura* decorador = GetWorld()->SpawnActor<AEDanio>(AEDanio::StaticClass());
	decorador->Decorador = proyectil;
}
