// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "Tank.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();	
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto theTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!theTank) { return nullptr; }
	return Cast<ATank>(theTank);
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto Player = GetPlayerTank();

	if (Player)
	{
		// Move toward player

		// Aim towards player
		GetControlledTank()->AimAt(Player->GetActorLocation());

		// Fire if ready
	}
}

