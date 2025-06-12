// KasaiRaito Studios All Rights Reserved


#include "AbiilitySystem/WarriorAttributeSet.h"
#include "GameplayEffectExtension.h"

#include "WarriorDebugHelper.h"

UWarriorAttributeSet::UWarriorAttributeSet()
{
	InitCurrentHealth(1.f);
	InitMaxHealth(1.f);
	
	InitCurrentRage(1.f);
	InitMaxRage(1.f);
	
	InitAttackPower(1.f);
	InitDefensePower(1.f);
}

void UWarriorAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	if(Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.0f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);
	}

	if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute())
	{
		const float NewCurrentRage = FMath::Clamp(GetCurrentRage(), 0.0f, GetMaxRage());

		SetCurrentRage(NewCurrentRage);
	}

	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float OldHealth = GetCurrentHealth();
		const float DamageDone = GetDamageTaken();

		const float NewHealth = FMath::Clamp(OldHealth - DamageDone, 0.0f, GetMaxHealth());

		SetCurrentHealth(NewHealth);

		const FString DebugString = FString::Printf(
			TEXT("OldHealth: %f, DamageDone: %f, NewHealth: %f"),
			OldHealth, DamageDone, NewHealth);

		Debug::Print(DebugString,FColor::Green);
		
		//PENDING TO MODIFY UI

		if (NewHealth == 0.0f)
		{
			Debug::Print(TEXT("Death"), FColor::Red);
		}
	}
}
