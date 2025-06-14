// KasaiRaito Studios All Rights Reserved


#include "Components/Combat/EnemyCombatComponent.h"

#include "WarriorDebugHelper.h"

void UEnemyCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (HitActor)
	{
		Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT(" is Hitting") + HitActor->GetActorNameOrLabel());
	}
	
}
