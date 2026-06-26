// Fill out your copyright notice in the Description page of Project Settings.


#include "AreaRapido.h"
#include "ERapido.h"
#include "Decorador.h"

void AAreaRapido::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IDecorador* proyectil = Cast<IDecorador>(OtherActor);
	if (proyectil == nullptr) return;
	AEnvoltura* decorador = GetWorld()->SpawnActor<AERapido>(AERapido::StaticClass());
	decorador->Decorador = proyectil;
}
