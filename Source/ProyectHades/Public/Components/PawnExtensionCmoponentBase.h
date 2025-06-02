// KasaiRaito Studios All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionCmoponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROYECTHADES_API UPawnExtensionCmoponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	template <class T>
	
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T*, APawn*>::Value, "'T' template parameter must be a subclass of APawn");
		return Cast<T>(GetOwner());
	}

	APawn* GetOwningPawn() const
	{
		return  GetOwningPawn<APawn>();
	}

	template <class T>
	T* GetOwningController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T*, AController*>::Value, "'T' template parameter must be a subclass of AController");
		return	GetOwningPawn<APawn>()->GetController<T>();
	}
};
