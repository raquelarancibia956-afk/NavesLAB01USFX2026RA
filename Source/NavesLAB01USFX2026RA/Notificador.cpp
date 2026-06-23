// Fill out your copyright notice in the Description page of Project Settings.


#include "Notificador.h"
#include "Suscriptor.h"

// Sets default values
ANotificador::ANotificador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANotificador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANotificador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANotificador::Inscribir(ISuscriptor* suscriptor)
{
	Suscriptores.Add(suscriptor);
}

void ANotificador::Desuscribir(ISuscriptor* suscriptor)
{
	Suscriptores.Remove(suscriptor);
}

void ANotificador::Notificar()
{
	for (ISuscriptor* suscriptor : Suscriptores) {
		suscriptor->AccionEspecial();
	}
}



