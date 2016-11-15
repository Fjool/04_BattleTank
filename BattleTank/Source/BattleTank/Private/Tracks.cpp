// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tracks.h"

// Sets a throttle between -1 and +1
void UTracks::SetThrottle(float Throttle)
{
	UE_LOG(LogTemp, Warning, TEXT("Tank throttle %s set to %f"), *GetName(), Throttle)

	// TODO clamp actual throttle value so player can't override

	auto ForceApplied  = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}
