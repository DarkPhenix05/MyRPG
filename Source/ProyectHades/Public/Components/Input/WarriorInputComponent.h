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