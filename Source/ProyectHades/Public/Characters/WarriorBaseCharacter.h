// KasaiRaito Studios All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitYSystemInterface.h"
#include "WarriorBaseCharacter.generated.h"

class UWarriorAbilitySystemComponent;
class UWarriorAttributeSet;
class UDataAsset_StartUpDataBase;
UCLASS()
class PROYECTHADES_API AWarriorBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarriorBaseCharacter();
	//~ Begin APawn Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End	APawn Interface.

	
protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End	APawn Interface.
	
	UPROPERTY(VisibleAnywhere,BlueprintreadOnly,Category = "AbilitySystem")
	UWarriorAbilitySystemComponent* WarriorAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere,BlueprintreadOnly,Category = "AbilitySystem")
	UWarriorAttributeSet* WarriorAttributeSet;

	/*
	 *Set up a SoftObjectPtr.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;

	
	
public:
	FORCEINLINE UWarriorAbilitySystemComponent* GetWarriorAbilitySystemComponent() const { return WarriorAbilitySystemComponent; }
	
	FORCEINLINE UWarriorAttributeSet* GetWarriorAttributeSet() const { return WarriorAttributeSet; }
};
