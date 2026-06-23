// Fill out your copyright notice in the Description page of Project Settings.


#include "ETBlindado.h"

AETBlindado::AETBlindado()
{
	SetMalla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	Vida = 250;
	Velocidad = 50.0f;
}

void AETBlindado::BeginPlay()
{
	Super::BeginPlay();
}

void AETBlindado::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
