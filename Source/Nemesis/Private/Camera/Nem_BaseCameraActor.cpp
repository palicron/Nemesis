// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera/Nem_BaseCameraActor.h"

#include "Components/ArrowComponent.h"

ANem_BaseCameraActor::ANem_BaseCameraActor()
{
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("Forwar Direction"));
}

void ANem_BaseCameraActor::BeginPlay()
{
	Super::BeginPlay();
	
}

FVector ANem_BaseCameraActor::GetCameraNormalForwardVector() const
{
	if(IsValid(ArrowComponent))
	{
		return ArrowComponent->GetForwardVector().GetSafeNormal();
	}

	return FVector::ForwardVector;
}

FVector ANem_BaseCameraActor::GetCameraNormalRightVector() const
{
	if(IsValid(ArrowComponent))
	{
		return ArrowComponent->GetRightVector().GetSafeNormal();
	}

	return FVector::RightVector;
}
