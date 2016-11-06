// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController::BeginPlay()"))

		auto ourTank = GetControlledTank();

	if (ourTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController: Controlling tank: %s"), *ourTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController: No tank under control."))
	}

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Tick tock"))
}

void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetControlledTank()) { return; }

	// Get world location through crosshair
	// if it hits the landscape
		// tell controlled tank to aim at this point

}
