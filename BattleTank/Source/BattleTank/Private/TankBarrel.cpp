// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// elevate barrel
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewElevation = FMath::Clamp(RelativeRotation.Pitch + ElevationChange, MinElevation, MaxElevation);
	
	SetRelativeRotation(FRotator(NewElevation, 0, 0));

	// rotate turret
}