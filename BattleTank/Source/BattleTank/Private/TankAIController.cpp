// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto TheirTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto OurTank   = Cast<ATank>(GetPawn());

	if (TheirTank && OurTank)
	{
		// Move toward player

		// Aim towards player
		OurTank->AimAt(TheirTank->GetActorLocation());
		OurTank->Fire(); // TODO Limit firing rate
	}
}