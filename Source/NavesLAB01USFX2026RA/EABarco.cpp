// Fill out your copyright notice in the Description page of Project Settings.


#include "EABarco.h"

AEABarco::AEABarco()
{
	SetMalla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim.Shape_Trim'"));
	Vida = 200;
	Velocidad = 50.0f;
}

void AEABarco::BeginPlay()
{
	Super::BeginPlay();
}

void AEABarco::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
