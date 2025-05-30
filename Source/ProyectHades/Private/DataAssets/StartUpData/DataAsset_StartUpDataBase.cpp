// KasaiRaito Studios All Rights Reserved


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbiilitySystem/WarriorAbilitySystemComponent.h"
#include "AbiilitySystem/Abilities/WarriorGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InWarriorASCTToGive,
                                                              int32 ApplyLevel)
{
	check(InWarriorASCTToGive);
	GrantAbilities(ActivateOnGivenAbilities, InWarriorASCTToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InWarriorASCTToGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive,
	UWarriorAbilitySystemComponent* InWarriorASCTToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<UWarriorGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability)
		{
			continue;	
		}

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InWarriorASCTToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		
		InWarriorASCTToGive->GiveAbility(AbilitySpec);
	}
	
}
