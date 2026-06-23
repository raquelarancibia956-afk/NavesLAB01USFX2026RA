// Fill out your copyright notice in the Description page of Project Settings.


#include "EAAvion.h"

AEAAvion::AEAAvion()
{
	SetMalla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	Vida = 200;
	Velocidad = 50.0f;
}
void AEAAvion::BeginPlay()
{
	Super::BeginPlay();
}

void AEAAvion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}