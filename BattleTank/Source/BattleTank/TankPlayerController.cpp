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
		// tell controlled tank to aim at this point
	}
	UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString())
}

// Return true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D( ViewportSizeX * CrossHairXLocation
								   , ViewportSizeY * CrossHairYLocation
								   );

	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// Line-trace along that look direction, see what we hit (up to max range)
		return GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	else
	{	return false;
	}
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation   = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel( HitResult
											, StartLocation
											, EndLocation
											, ECollisionChannel::ECC_Visibility
											))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	else
	{	HitLocation = FVector(0.f);
		return false;
	}
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation;

	// De-project screen position of crosshair to a world direction
	return DeprojectScreenPositionToWorld( ScreenLocation.X
										 , ScreenLocation.Y
										 , WorldLocation
										 , LookDirection
										 );
}
