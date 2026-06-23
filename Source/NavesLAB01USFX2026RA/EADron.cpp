// Fill out your copyright notice in the Description page of Project Settings.


#include "EADron.h"

AEADron::AEADron()
{
	SetMalla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	Vida = 100;
	Velocidad = 100.0f;
}
void AEADron::BeginPlay()
{
	Super::BeginPlay();
}

void AEADron::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
