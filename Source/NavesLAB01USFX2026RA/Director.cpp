// Fill out your copyright notice in the Description page of Project Settings.


#include "Director.h"
#include "Aplastador.h"
#include "Muro.h"
#include "FabricaMEstructura.h"

// Sets default values
ADirector::ADirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADirector::SetBuilder(AFabricaMEstructura* builder)
{
	Builder = builder;
}

void ADirector::SetObjeto(AAplastador* objeto)
{
	Aplastador = objeto;
}

AAplastador* ADirector::AplastadorSimple(FVector posicion)
{
	//Aplastador = GetWorld()->SpawnActor<AAplastador>(posicion, FRotator::ZeroRotator);
	Builder->InicializarEstructura();
	Builder->SetPosicion(posicion);
	Aplastador->Muros.Add(Builder->Fabricar());
	return Aplastador;
}


