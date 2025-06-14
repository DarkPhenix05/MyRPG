// KasaiRaito Studios All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/UI/PawnUIComponent.h"
#include "HeroUIComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROYECTHADES_API UHeroUIComponent : public UPawnUIComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FonPercentChangeDelete OnCurrentRageChange;
	
};
