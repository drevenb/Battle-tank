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
	UE_LOG(LogTemp, Warning, TEXT("Hello"));
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if(!GetControlledTank()) { return; }

	//Get world location if linetrace through crosshair
	//if it hits the landscape
		//Tell controlled tank to aim at this point
}