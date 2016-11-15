// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Tracks.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTracks : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Input) void SetThrottle(float Throttle);

	// Max force per track in newtons
	UPROPERTY(EditDefaultsOnly)	float TrackMaxDrivingForce = 400000; // 40 tonne tank @ 10m/s accelleration
};
