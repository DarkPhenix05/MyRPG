// KasaiRaito Studios All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbiilitySystem/Abilities/WarriorGameplayAbility.h"
#include "WarriorHeroGameplayAbility.generated.h"

class AWarriorHeroCharacter;
class AWarriorHeroController;
/**
 * 
 */
UCLASS()
class PROYECTHADES_API UWarriorHeroGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")	
	AWarriorHeroCharacter* GetHeroCharacterFromActorInfo();
	
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarriorHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();	
	
private:
	TWeakObjectPtr<AWarriorHeroCharacter> CashedWarriorHeroCharacter;
	TWeakObjectPtr<AWarriorHeroController> CashedWarriorHeroController;
};
