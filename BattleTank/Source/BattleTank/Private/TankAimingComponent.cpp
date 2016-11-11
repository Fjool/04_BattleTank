// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
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

// respond to aim instructions from the tank
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel)
	{	UE_LOG(LogTemp, Warning, TEXT("No barrel available"))
		return; 
	}
	 
	FVector OutLaunchVelocity;

	if (UGameplayStatics::SuggestProjectileVelocity ( this
													, OutLaunchVelocity
													, Barrel->GetSocketLocation(FName("Projectile"))
													, HitLocation
													, LaunchSpeed
													, false
													, 0
													, 0
													, ESuggestProjVelocityTraceOption::DoNotTrace
													))
	{	MoveBarrelTowards(OutLaunchVelocity.GetSafeNormal());
		UE_LOG(LogTemp, Warning, TEXT("%f: Solution found"), GetWorld()->GetTimeSeconds())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%f: No solution found"), GetWorld()->GetTimeSeconds())
	}

}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator  = AimDirection.Rotation();
	auto DeltaRotator  = AimAsRotator - BarrelRotator;
	
	if (!Barrel)
	{	UE_LOG(LogTemp, Warning, TEXT("NO BARREL"))
		return;
	}

	Barrel->Elevate(5);	// TODO Remove magic number
}