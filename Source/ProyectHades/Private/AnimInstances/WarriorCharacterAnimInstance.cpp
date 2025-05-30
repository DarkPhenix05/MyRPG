// KasaiRaito Studios All Rights Reserved


#include "AnimInstances/WarriorCharacterAnimInstance.h"

#include <string>

#include "Characters/WarriorBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


void UWarriorCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter =  Cast<AWarriorBaseCharacter> (TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UWarriorCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComponent)
	{
		return;
	}

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();

	bHasAcceleration = (OwningMovementComponent->GetCurrentAcceleration().SizeSquared() > 0.0f);
}

