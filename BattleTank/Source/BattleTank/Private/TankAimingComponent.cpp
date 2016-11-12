// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "Turret.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true; // TODO should this really tick?

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	UE_LOG(LogTemp, Warning, TEXT("Setting barrel to %s"), *BarrelToSet->GetName())
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTurret* TurretToSet)
{
	UE_LOG(LogTemp, Warning, TEXT("Setting turret to %s"), *TurretToSet->GetName())
	Turret = TurretToSet;
}

// respond to aim instructions from the tank
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel || !Turret)
	{	UE_LOG(LogTemp, Warning, TEXT("Missing elements of tank aiming system"))
		return; 
	}
	 
	FVector OutLaunchVelocity;

	if (UGameplayStatics::SuggestProjectileVelocity ( this
													, OutLaunchVelocity
													, Barrel->GetSocketLocation(FName("Projectile"))
													, HitLocation
													, LaunchSpeed
													, false, 0, 0
													, ESuggestProjVelocityTraceOption::DoNotTrace
													))
	{	MoveBarrelTowards(OutLaunchVelocity.GetSafeNormal());	
	}

	RotateTurretTowards(HitLocation.GetSafeNormal());
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	
	if (!Barrel) {	UE_LOG(LogTemp, Warning, TEXT("NO BARREL"))
					return;
				 }
	{	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
		auto  AimAsRotator = AimDirection.Rotation();
		auto  DeltaRotator = AimAsRotator - BarrelRotator;
	
		Barrel->Elevate(DeltaRotator.Pitch);
	}
}

void UTankAimingComponent::RotateTurretTowards(FVector AimDirection)
{
	if (!Turret) { UE_LOG(LogTemp, Warning, TEXT("NO TURRET"))
				   return;
				 }
	else
	{	auto TurretRotator = Turret->GetForwardVector().Rotation();
		auto  AimAsRotator = AimDirection.Rotation();
		auto  DeltaRotator = AimAsRotator - TurretRotator;
	
		Turret->Rotate(DeltaRotator.Yaw);
	}
}