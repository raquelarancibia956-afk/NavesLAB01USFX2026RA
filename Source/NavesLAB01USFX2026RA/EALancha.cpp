// Fill out your copyright notice in the Description page of Project Settings.


#include "EALancha.h"

AEALancha::AEALancha()
{
	SetMalla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe_90.Shape_Pipe_90'"));
	Vida = 100;
	Velocidad = 100.0f;
}
void AEALancha::BeginPlay()
{
	Super::BeginPlay();
}

void AEALancha::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}