// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "Nem_BaseCameraActor.generated.h"

class ANem_BaseCharacter;
/**
 * 
 */
UCLASS()
class NEMESIS_API ANem_BaseCameraActor : public ACameraActor
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category= "Player Tager")
	ANem_BaseCharacter* CurrentLocalPlayer;

	virtual void BeginPlay() override;
	
};
