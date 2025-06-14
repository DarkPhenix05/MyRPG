// KasaiRaito Studios All Rights Reserved


#include "AbiilitySystem/WarriorAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "WarriorFunctionLibrary.h"
#include "WarriorGameplayTags.h"
#include "Interfaces/PawnUIInterface.h"
#include "Components/UI/PawnUIComponent.h"
#include "Components/UI/HeroUIComponent.h"

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
#pragma region GET PAWN UI INTERFACE/COMPONENT
	if (CachedPawnUIInterface.IsValid())
	{
		CachedPawnUIInterface = TWeakInterfacePtr<IPawnUIInterface>(Data.Target.GetAvatarActor());
		//CachedPawnUIInterface = Cast<IPawnUIInterface>(Data.Target.GetAvatarActor()); //Alternative Sintaxis
	}

	checkf(CachedPawnUIInterface.IsValid(), TEXT("%s didn't implement IPawnUIInterface"),  *Data.Target.GetAvatarActor()->GetActorNameOrLabel());
	UPawnUIComponent* PawnUIComponent = CachedPawnUIInterface->GetPawnUIComponent();

	checkf(PawnUIComponent, TEXT("Couldn't extract a PawnUIComponent form %s"), *Data.Target.GetAvatarActor()->GetActorNameOrLabel());
#pragma endregion
	
		//SET CURRENT HEALTH IN UI
	if(Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.0f, GetMaxHealth());
		
		SetCurrentHealth(NewCurrentHealth);

		PawnUIComponent->OnCurrentHealthChanged.Broadcast(GetCurrentHealth()/GetMaxHealth());
	}
		//SET RAGE VAL IN UI
	if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute())
	{
		const float NewCurrentRage = FMath::Clamp(GetCurrentRage(), 0.0f, GetMaxRage());
		
		SetCurrentRage(NewCurrentRage);

		#pragma region GET HERO UI COMPONENT && BRODCAST CHANGE
		if (UHeroUIComponent* HeroUIComponent = CachedPawnUIInterface->GetHeroUIComponent())
		{
			HeroUIComponent->OnCurrentRageChange.Broadcast(GetCurrentRage()/GetMaxRage());
		}
		#pragma endregion
	}
		//UPDATE CURRENT HEALTH IN UI
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
		
		PawnUIComponent->OnCurrentHealthChanged.Broadcast(GetCurrentHealth()/GetMaxHealth());
		
		if (NewHealth == 0.0f)
		{
			UWarriorFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), WarriorGameplayTags::Shared_Status_Death);
		}
	}
}
