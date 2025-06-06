// KasaiRaito Studios All Rights Reserved


#include "WarriorTypes/WarriorStructTypes.h"
#include "AbiilitySystem/Abilities/WarriorHeroGameplayAbility.h"

bool FWarriorHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
