// KasaiRaito Studios All Rights Reserved


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbiilitySystem/WarriorAbilitySystemComponent.h"
#include "AbiilitySystem/Abilities/WarriorGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCTToGive,
                                                              int32 ApplyLevel)
{
	check(InASCTToGive);
	GrantAbilities(ActivateOnGivenAbilities, InASCTToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASCTToGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive,
	UWarriorAbilitySystemComponent* InASCTToGive, int32 ApplyLevel)
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
		AbilitySpec.SourceObject = InASCTToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		
		InASCTToGive->GiveAbility(AbilitySpec);
	}
	
}
