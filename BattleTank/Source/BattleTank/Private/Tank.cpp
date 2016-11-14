// Fill out your copyright notice in the Description page of Project Settings.
#include "BattleTank.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Pass on components to aiming system
void ATank::SetBarrelReference(UTankBarrel* BarrelToSet){ Barrel = BarrelToSet; TankAimingComponent->SetBarrelReference(Barrel     ); }
void ATank::SetTurretReference(UTurret*     TurretToSet){						TankAimingComponent->SetTurretReference(TurretToSet); }

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	if (Barrel)
	{	// spawn a projectile at the socked location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>( ProjectileBlueprint
															 , Barrel->GetSocketLocation(FName("Projectile"))
															 , Barrel->GetSocketRotation(FName("Projectile"))
															 );
		Projectile->LaunchProjectile(LaunchSpeed);
	}
}