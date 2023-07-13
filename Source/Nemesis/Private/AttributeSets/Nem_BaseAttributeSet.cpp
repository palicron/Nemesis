// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSets/Nem_BaseAttributeSet.h"

#include "Net/UnrealNetwork.h"

void UNem_BaseAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNem_BaseAttributeSet, Health, OldHealth);
}

void UNem_BaseAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNem_BaseAttributeSet, MaxHealth, OldMaxHealth);
}

void UNem_BaseAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldArmor)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNem_BaseAttributeSet, Armor, OldArmor);
}

void UNem_BaseAttributeSet::OnRep_Shield(const FGameplayAttributeData& OldShield)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNem_BaseAttributeSet, Shield, OldShield);
}

void UNem_BaseAttributeSet::OnRep_MaxShield(const FGameplayAttributeData& OldMaxShield)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNem_BaseAttributeSet, MaxShield, OldMaxShield);
}

void UNem_BaseAttributeSet::OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNem_BaseAttributeSet, MovementSpeed, OldMovementSpeed);
}

void UNem_BaseAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UNem_BaseAttributeSet, Health, COND_None, REPNOTIFY_Always);
}
