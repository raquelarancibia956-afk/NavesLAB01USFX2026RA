// Fill out your copyright notice in the Description page of Project Settings.


#include "ETTancque.h"

AETTancque::AETTancque()
{
	SetMalla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Tube.Shape_Tube'"));
	Vida = 200;
	Velocidad = 100.0f;
}
void AETTancque::BeginPlay()
{
	Super::BeginPlay();
}

void AETTancque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}