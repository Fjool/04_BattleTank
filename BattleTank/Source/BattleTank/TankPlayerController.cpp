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
	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController::BeginPlay()"))

	auto ourTank = GetControlledTank();

	if (ourTank) 
	{	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: Controlling tank: %s"), *ourTank->GetName()) 
	}
	else
	{	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController: No tank under control."))
	}

}
