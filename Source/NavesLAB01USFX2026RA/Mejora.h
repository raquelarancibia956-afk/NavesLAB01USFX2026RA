// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Efecto.h"
#include "Mejora.generated.h"

UCLASS()
class NAVESLAB01USFX2026RA_API AMejora : public AActor, public IEfecto
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMejora();
	UStaticMeshComponent* Malla;
	UFUNCTION()
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void AplicarEfecto(ANavesLAB01USFX2026RAPawn* objetivo) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
