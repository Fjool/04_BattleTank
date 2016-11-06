// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AIController::BeginPlay()"))

	auto ourTank   = GetControlledTank();
	auto theirTank = GetPlayerTank();

	if (ourTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController: Controlling tank: %s"), *ourTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController: No tank under control."))
	}

	if (theirTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController: Player tank: %s"), *theirTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController: Player tank: <none>"))
	}

}

ATank* ATankAIController::GetPlayerTank() const
{
	auto theTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!theTank) { return nullptr; }
	return Cast<ATank>(theTank);
}