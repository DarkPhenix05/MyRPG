// KasaiRaito Studios All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"

/**
*
*/
UCLASS()
class PROYECTHADES_API UWarriorInputComponent : public UEnhancedInputComponent
{
    GENERATED_BODY()
public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, 
                      ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);

	template<class UserObject, typename CallbackFunc>	
	void BindAbilityAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, CallbackFunc InputPressedFunc, CallbackFunc InputRelasedFunc);

};

template<class UserObject, typename CallbackFunc>
inline void UWarriorInputComponent::BindNativeAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
    checkf(InInputConfig, TEXT("UWarriorInputComponent::BindNativeAction - InInputConfig is null!"));

	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
    {
        BindAction(FoundAction, TriggerEvent, ContextObject, Func);
    }
	
}

template <class UserObject, typename CallbackFunc>
void UWarriorInputComponent::BindAbilityAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject,
	CallbackFunc InputPressedFunc, CallbackFunc InputRelasedFunc)
{
	checkf(InInputConfig, TEXT("UWarriorInputComponent::BindNativeAction - InInputConfig is null!"));

	for (const FWarriorInputActionConfig& AbilityInputActionsConfig : InInputConfig->AbilityInputActions)
	{
		if (!AbilityInputActionsConfig.IsValid())
		{
			continue;
		}

		BindAction(AbilityInputActionsConfig.InputAction, ETriggerEvent::Started, ContextObject, InputPressedFunc,
			AbilityInputActionsConfig.InputTag);
		BindAction(AbilityInputActionsConfig.InputAction, ETriggerEvent::Completed, ContextObject, InputRelasedFunc,
			AbilityInputActionsConfig.InputTag);
	}
}

