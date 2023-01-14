// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category="Components")
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category="Components")
	UCameraComponent* CameraComp;
	UPROPERTY(EditAnywhere, Category="Movement")
	float Speed = 500.0f;
	UPROPERTY(EditAnywhere, Category="Movement")
	float TurnRate = 50.0f;

	void Move(float Value);
	void Turn(float Value);

	APlayerController* PlayerControllerRef;
};

