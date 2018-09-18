// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

//Called when the game starts or when spawned
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if(ControlledTank)
	{
	UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing a %s"), *(ControlledTank->GetName()));
	}
	else
	{
	UE_LOG(LogTemp, Error, TEXT("PlayerController not possessing a tank!"));
	}
}

//Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; //Out Parameter

	if (GetSightRayHitLocation(HitLocation)) //Has "side-effect", is going to linetrace
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString())
		//TODO Tell controlled tank to aim at this point
	}
}

//Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	//"De-project" the screen position of the crosshair to a world direction
	//Line-trace along that look direction, and see what we hit (up to max range)
	return true;
}