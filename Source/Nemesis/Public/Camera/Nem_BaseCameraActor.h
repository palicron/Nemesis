// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "Nem_BaseCameraActor.generated.h"

class UArrowComponent;
class ANem_BaseCharacter;
/**
 * 
 */
UCLASS()
class NEMESIS_API ANem_BaseCameraActor : public ACameraActor
{
	GENERATED_BODY()

	ANem_BaseCameraActor();

protected:

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category= "Player Tager")
	ANem_BaseCharacter* CurrentLocalPlayer;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category= "Player Tager")
	UArrowComponent* ArrowComponent;

	virtual void BeginPlay() override;


public:

	UFUNCTION(BlueprintCallable)
	FVector GetCameraNormalForwardVector() const;
	
	UFUNCTION(BlueprintCallable)
	FVector GetCameraNormalRightVector() const;
	
};
