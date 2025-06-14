// KasaiRaito Studios All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbiilitySystem/WarriorAbilitySystemComponent.h"
#include "WarriorAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

class IPawnUIInterface;
/**
 * 
 */
UCLASS()
class PROYECTHADES_API UWarriorAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UWarriorAttributeSet();
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data) override;
	
	//HEALTH
	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, CurrentHealth)
	
	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, MaxHealth)
	
	//RAGE
	UPROPERTY(BlueprintReadOnly, Category = "Rage")
	FGameplayAttributeData CurrentRage;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, CurrentRage)
	
	UPROPERTY(BlueprintReadOnly, Category = "Rage")
	FGameplayAttributeData MaxRage;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, MaxRage)

	//Damage
	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, AttackPower)
	
	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData DefensePower;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, DefensePower)
	
	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData DamageTaken;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, DamageTaken)

private:
	TWeakInterfacePtr<IPawnUIInterface> CachedPawnUIInterface;
};
