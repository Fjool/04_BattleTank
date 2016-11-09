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

	FVector HitLocation; // Out parameter

	// Get world location through crosshair
	if (GetSightRayHitLocation(HitLocation)) // "side-effect"
	{
		// If it hits landscape
	}

	// if it hits the landscape
		// tell controlled tank to aim at this point

}

// Return true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Get camera centre
	// Trace ray out from camera, through crosshair until hit landscape
	// Set HitLocation = Point at which ray strikes landscape
	// Return true if ray strikes landscape, false otherwise

	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	// De-project screen position of crosshair to a world direction
	// Line-trace along that look direction
	// See what we hit (up to max range)

	return true;
}