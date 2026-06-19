// Fill out your copyright notice in the Description page of Project Settings.


#include "Director.h"
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

void ADirector::AplastadorSimple()
{
	Builder->InicializarEstructura();
	//Builder->SetAlt
}


