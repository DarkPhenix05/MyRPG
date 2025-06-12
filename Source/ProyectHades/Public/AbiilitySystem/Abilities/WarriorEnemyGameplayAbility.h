// KasaiRaito Studios All Rights Reserved

#pragma once

class UEnemyCombatComponent;
class AWarriorEnemyCharacter;
#include "CoreMinimal.h"
#include "AbiilitySystem/Abilities/WarriorGameplayAbility.h"
#include "WarriorEnemyGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class PROYECTHADES_API UWarriorEnemyGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category= "WWarrior|Ability")
	AWarriorEnemyCharacter* GetEnemyCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "WWarrior|Ability")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AWarriorEnemyCharacter> CachedWarriorEnemyCharacter;
};