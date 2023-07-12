// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Nem_BaseCharacter.generated.h"

class ANen_GameModeBase;
class ANem_BaseCameraActor;
UCLASS()
class NEMESIS_API ANem_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	ANem_BaseCharacter();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

protected:
	UFUNCTION()
	void InitReference();

	UPROPERTY(BlueprintReadWrite,Transient)
	ANen_GameModeBase* GameModeRef;
	
	UPROPERTY(BlueprintReadWrite,Transient)
	ANem_BaseCameraActor* CurrentMainCamera;
	
	UPROPERTY(BlueprintReadWrite,Transient)
	FVector CurrentForwardMoveVector;

	UPROPERTY(BlueprintReadWrite,Transient)
	FVector CurrentRightMoveVector;

	UFUNCTION(BlueprintCallable)
	virtual void UpDateCameraReference( ANem_BaseCameraActor* newCamera);
	
	virtual void BeginPlay() override;
	
	void Move(const FInputActionValue& Value);

public:	

	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

};
