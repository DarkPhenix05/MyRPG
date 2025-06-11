// KasaiRaito Studios All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PawnCombatInteface.generated.h"

class UPawnCombatComponent;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPawnCombatInteface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROYECTHADES_API IPawnCombatInteface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual UPawnCombatComponent* GetPawnCombatComponent() const = 0;
};
