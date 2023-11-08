// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere);
	float RestartDelay = 5.f;

	FTimerHandle RestartTimer;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> LoseGameWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> WinGameWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	UPROPERTY()
	UUserWidget* HUD;
};
