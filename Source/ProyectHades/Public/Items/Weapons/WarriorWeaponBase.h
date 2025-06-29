// KasaiRaito Studios All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WarriorWeaponBase.generated.h"

class UBoxComponent;

DECLARE_DELEGATE_OneParam(FOnTargetInteractedDelegate, AActor*)
UCLASS()
class PROYECTHADES_API AWarriorWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWarriorWeaponBase();

	FOnTargetInteractedDelegate OnWeaponHitTarget;
	FOnTargetInteractedDelegate  OnWeaponPulledFromTarget;

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Weapons")
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Weapons")
	UBoxComponent* WeaponCollisionBox;

	UFUNCTION()
	virtual void OnCollisionBoXBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnCollisionBoXEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
public:
	FORCEINLINE UBoxComponent* GetWeaponCollisionBox() const { return WeaponCollisionBox; }
};