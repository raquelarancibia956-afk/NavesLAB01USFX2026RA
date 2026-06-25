// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavesLAB01USFX2026RAPawn.h"
#include "NavesLAB01USFX2026RAProjectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Estado.h"
#include "Quieto.h"
#include "Efecto.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

const FName ANavesLAB01USFX2026RAPawn::MoveForwardBinding("MoveForward");
const FName ANavesLAB01USFX2026RAPawn::MoveRightBinding("MoveRight");
const FName ANavesLAB01USFX2026RAPawn::FireForwardBinding("FireForward");
const FName ANavesLAB01USFX2026RAPawn::FireRightBinding("FireRight");
const FName ANavesLAB01USFX2026RAPawn::RunBinding("Run");

ANavesLAB01USFX2026RAPawn::ANavesLAB01USFX2026RAPawn()
{	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);

	ShipMeshComponent->SetCollisionObjectType(ECC_EngineTraceChannel2);
	ShipMeshComponent->SetCollisionResponseToChannel(ECC_EngineTraceChannel3,ECR_Overlap);
	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;

	Danio = 20;
	Vida = 100;

}

void ANavesLAB01USFX2026RAPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);
	PlayerInputComponent->BindAxis(RunBinding);

}

void ANavesLAB01USFX2026RAPawn::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);
	float bCorrer = GetInputAxisValue(RunBinding); // TODO: cambiar a 1


	Estado->Moverse(ForwardValue, RightValue, bCorrer, DeltaSeconds);
	/*
	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * multiplicadorVelocidad * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		
		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}
	*/
	
	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	Estado->Disparar(FireForwardValue, FireRightValue);
	// Try and fire a shot
	//FireShot(FireDirection);
}

void ANavesLAB01USFX2026RAPawn::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				ANavesLAB01USFX2026RAProjectile* bala;
				bala = World->SpawnActor<ANavesLAB01USFX2026RAProjectile>(SpawnLocation, FireRotation);
				bala->SetDanio(Danio);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANavesLAB01USFX2026RAPawn::ShotTimerExpired, FireRate);

			// try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}

			bCanFire = false;
		}
	}
}

void ANavesLAB01USFX2026RAPawn::ShotTimerExpired()
{
	bCanFire = true;
}

void ANavesLAB01USFX2026RAPawn::BeginPlay()
{
	Super::BeginPlay();
	Estado = GetWorld()->SpawnActor<AQuieto>(AQuieto::StaticClass());
	Estado->Jugador = this;
}

void ANavesLAB01USFX2026RAPawn::RecibirDanio(int cantidad)
{
	Vida -= cantidad;
	if (Vida <= 0) {
		const FName CurrentLevelName = FName(GetWorld()->GetName());
		UGameplayStatics::OpenLevel(this, CurrentLevelName);
	}
}

void ANavesLAB01USFX2026RAPawn::SetEstrategia(IEfecto* estrategia)
{
	Estrategia = estrategia;
	Estrategia->AplicarEfecto(this);
}

void ANavesLAB01USFX2026RAPawn::CambiarEstado(AEstado* nuevoEstado)
{
	Estado = nuevoEstado;
}
