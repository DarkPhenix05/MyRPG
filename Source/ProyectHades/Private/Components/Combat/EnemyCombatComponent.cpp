// KasaiRaito Studios All Rights Reserved


#include "Components/Combat/EnemyCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "WarriorGameplayTags.h"

#include "WarriorDebugHelper.h"

void UEnemyCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (HitActor)
	{
		//Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT(" is Hitting") + HitActor->GetActorNameOrLabel());
		if (OverlappingActors.Contains(HitActor))
		{
			return;
		}

		OverlappingActors.AddUnique(HitActor);

		//TO DO:: implement Block check
		bool bIsValidBlock = false;

		const bool bIsPLayerBlocking = false;
		const bool bIsMyAttackUnblocable = false;

		if (bIsPLayerBlocking && !bIsMyAttackUnblocable)
		{
			//TO DO:: Handle successful block
		}

		FGameplayEventData EventData;
		EventData.Instigator = GetOwningPawn();
		EventData.Target = HitActor;
		
		if (bIsValidBlock)
		{
			
		}
		else
		{
			UAbilitySystemBlueprintLibrary::SendGameplayEventToActor
			(
				GetOwningPawn(),
				WarriorGameplayTags::Shared_Event_MeleeHit,
				EventData	
			);
		}
	}
	
}
