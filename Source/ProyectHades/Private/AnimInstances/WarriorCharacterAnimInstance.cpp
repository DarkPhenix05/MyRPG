// KasaiRaito Studios All Rights Reserved


#include "AnimInstances/WarriorCharacterAnimInstance.h"

#include <string>

#include "Characters/WarriorBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "WarriorDebugHelper.h"

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
		Debug::Print(TEXT("OwningCharacter or OwningMovementComponent is null in UWarriorCharacterAnimInstance::NativeThreadingUpdate"));
		return;
	}

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();

	bHasAcceleration = (OwningMovementComponent->GetCurrentAcceleration().SizeSquared() > 0.0f);
}

