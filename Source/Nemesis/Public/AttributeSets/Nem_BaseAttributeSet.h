// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "Nem_BaseAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class NEMESIS_API UNem_BaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()


public:

	UPROPERTY(ReplicatedUsing = OnRep_Health, EditAnywhere,BlueprintReadWrite,Category="Attribute Health")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UNem_BaseAttributeSet,Health)
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UPROPERTY(ReplicatedUsing = OnRep_MaxHealth, EditAnywhere,BlueprintReadWrite,Category="Attribute Max Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UNem_BaseAttributeSet,MaxHealth)
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

	UPROPERTY(ReplicatedUsing = OnRep_Armor, EditAnywhere,BlueprintReadWrite,Category="Attribute Armor")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UNem_BaseAttributeSet,Armor)
	UFUNCTION()
	virtual void OnRep_Armor(const FGameplayAttributeData& OldArmor);

	UPROPERTY(ReplicatedUsing = OnRep_Shield, EditAnywhere,BlueprintReadWrite,Category="Attribute Shield")
	FGameplayAttributeData Shield;
	ATTRIBUTE_ACCESSORS(UNem_BaseAttributeSet,Shield)
	UFUNCTION()
	virtual void OnRep_Shield(const FGameplayAttributeData& OldShield);

	UPROPERTY(ReplicatedUsing = OnRep_MaxShield, EditAnywhere,BlueprintReadWrite,Category="Attribute MaxShield")
	FGameplayAttributeData MaxShield;
	ATTRIBUTE_ACCESSORS(UNem_BaseAttributeSet,MaxShield)
	UFUNCTION()
	virtual void OnRep_MaxShield(const FGameplayAttributeData& OldMaxShield);

	UPROPERTY(ReplicatedUsing = OnRep_MovementSpeed, EditAnywhere,BlueprintReadWrite,Category="Attribute MovementSpeed")
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UNem_BaseAttributeSet,MovementSpeed)
	UFUNCTION()
	virtual void OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed);


	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
};
