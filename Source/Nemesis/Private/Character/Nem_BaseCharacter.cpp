// Fill out your copyright notice in the Description page of Project Settings.



#include "Nemesis/Public/Character/Nem_BaseCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Nen_GameModeBase.h"
#include "Camera/Nem_BaseCameraActor.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Nemesis/Public/Camera/Nem_CameraComponent.h"

// Sets default values
ANem_BaseCharacter::ANem_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	GetCharacterMovement()->bOrientRotationToMovement = true; 
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	//@TODO ADD TO A DATA ASSET
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	
}


// Called when the game starts or when spawned
void ANem_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	InitReference();
}

// Called every frame
void ANem_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANem_BaseCharacter::InitReference()
{
	GameModeRef = Cast<ANen_GameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if(IsValid(GameModeRef))
	{
		UpDateCameraReference(GameModeRef->GetActiveCameraRef());
		GameModeRef->FOnCameraRefGetDelegate.AddDynamic(this,&ThisClass::UpDateCameraReference);
	}
}


// Called to bind functionality to input
void ANem_BaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ANem_BaseCharacter::Move);
	}
}

void ANem_BaseCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddMovementInput(CurrentForwardMoveVector, MovementVector.Y);
		AddMovementInput(CurrentRightMoveVector, MovementVector.X);
	}
}

void ANem_BaseCharacter::UpDateCameraReference( ANem_BaseCameraActor* newCamera)
{
	CurrentMainCamera = newCamera;
	if(IsValid(CurrentMainCamera))
	{
		CurrentForwardMoveVector = CurrentMainCamera->GetCameraNormalForwardVector();
		CurrentRightMoveVector = CurrentMainCamera->GetCameraNormalRightVector();
	}
}
