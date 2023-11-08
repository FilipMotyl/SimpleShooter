// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	HUD = CreateWidget(this, HUDWidgetClass, TEXT("HUSUIWidget"));
	if (HUD != nullptr)
	{
		HUD->AddToViewport();
	}
}

void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	HUD->RemoveFromViewport();
	if (bIsWinner)
	{
		UUserWidget* WinScreen = CreateWidget(this, WinGameWidgetClass, TEXT("WinGameUIWidget"));
		if (WinScreen != nullptr)
		{
			WinScreen->AddToViewport();
		}
		
	}
	else if (!bIsWinner)
	{
		UUserWidget* LoseScreen = CreateWidget(this, LoseGameWidgetClass, TEXT("LoseGameUIWidget"));
		if (LoseScreen != nullptr)
		{
			LoseScreen->AddToViewport();
		}
	}
	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}