// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Nen_GameModeBase.generated.h"

class ANem_BaseCameraActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCameraRefGetSignature,ANem_BaseCameraActor*,NewCamera);
UCLASS()
class NEMESIS_API ANen_GameModeBase : public AGameMode
{
	GENERATED_BODY()


protected:

	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Transient,Category="Camera Control")
	ANem_BaseCameraActor* ActiveCamaraRef;

	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable)
	void GetFirstLocalCameraInLevel();

public:
	
	UPROPERTY(BlueprintAssignable)
	FOnCameraRefGetSignature FOnCameraRefGetDelegate;
	
	FORCEINLINE ANem_BaseCameraActor* GetActiveCameraRef() const {return ActiveCamaraRef;}
	
};
