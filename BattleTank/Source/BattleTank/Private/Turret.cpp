// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Turret.h"

void UTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);

	float RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float NewRotation = RelativeRotation.Yaw + RotationChange;

	UE_LOG(LogTemp, Warning, TEXT("Rotating turret %f"), NewRotation)

	SetRelativeRotation(FRotator(0, NewRotation, 0));
}