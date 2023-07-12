// Fill out your copyright notice in the Description page of Project Settings.


#include "Nen_GameModeBase.h"

#include "Camera/Nem_BaseCameraActor.h"
#include "Kismet/GameplayStatics.h"

void ANen_GameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	GetFirstLocalCameraInLevel();

}

void ANen_GameModeBase::GetFirstLocalCameraInLevel()
{
	TArray<AActor*> AllStartCamera ; 
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(),ANem_BaseCameraActor::StaticClass(),FName("Start_Camera"),AllStartCamera);

	if(!AllStartCamera.IsEmpty() &&  IsValid(AllStartCamera[0]))
	{
		ActiveCamaraRef = Cast<ANem_BaseCameraActor>(AllStartCamera[0]);
		if(IsValid(ActiveCamaraRef))
		{
			FOnCameraRefGetDelegate.Broadcast(ActiveCamaraRef);
		}
	}
}
