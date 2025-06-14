// KasaiRaito Studios All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionCmoponentBase.h"
#include "PawnUIComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FonPercentChangeDelete, float, NewPecent);
/**
 * 
 */
UCLASS()
class PROYECTHADES_API UPawnUIComponent : public UPawnExtensionCmoponentBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable)
	FonPercentChangeDelete OnCurrentHealthChanged;
};
