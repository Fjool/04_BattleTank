// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	// find barrel's current aiming vector
	// work out difference

	// consider frametime 

	// elevate barrel by Z difference
	// rotate turret by Y difference

	UE_LOG(LogTemp, Warning, TEXT("Elevating %s"), DegreesPerSecond)
}
