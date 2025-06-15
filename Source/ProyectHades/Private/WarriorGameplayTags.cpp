// KasaiRaito Studios All Rights Reserved

#include "WarriorGameplayTags.h"

namespace  WarriorGameplayTags
{
	/** INPUT TAGS **/
		//Movement
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "Input.Move" );
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "Input.Look");
		//Equip
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipAxe, "Input.EquipAxe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipAxe, "Input.UnequipAxe");
		//Attack
			//Light
	UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack_Axe, "Input.LightAttack.Axe");
			//Heavy
	UE_DEFINE_GAMEPLAY_TAG(InputTag_HeavyAttack_Axe, "Input.HeavyAttack.Axe");

	/** Player TAGS **/
		//Equip Axe ABILITY
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Axe, "Player.Ability.Equip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip_Axe, "Player.Ability.Unequip.Axe");
		//Attack
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light_Axe, "Player.Ability.Attack.Light.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Heavy_Axe, "Player.Ability.Attack.Heavy.Axe");
		//HIT VFX
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Hit_Pause, "Player.Ability.Hit.Pause");
		//Weapon
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe, "Player.Weapon.Axe");
		//Equip Axe EVENTS
	UE_DEFINE_GAMEPLAY_TAG(Player_Events_Equip_Axe, "Player.Event.Equip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Events_Unequip_Axe, "Player.Event.Unequip.Axe");
		//HIT VFX EVENTS
	UE_DEFINE_GAMEPLAY_TAG(Player_Events_Hit_Pause, "Player.Event.Hit.Pause");
		//Status
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_JumpToFinisher, "Player.Status.JumpToFinisher");
		//SetByCaller
	UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_AttackType_Light, "Player.SetByCaller.AttackType.Light");
	UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_AttackType_Heavy, "Player.SetByCaller.AttackType.Heavy");

	/** Enemy TAGS **/
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon, "Enemy.Weapon")
	
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Melee, "Enemy.Ability.Melee")
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Ranged, "Enemy.Ability.Ranged")

	UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_Strafing, "Enemy.Status.Strafing");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_UnderAttack,"Enemy.Status.UnderAttack");

	/** Shared TAGS **/
		//React to Hit
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_HitReact_Light, "Shared.Ability.HitReact.Light");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_HitReact_Heavy, "Shared.Ability.HitReact.Heavy");
		//Death
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_Death, "Shared.Ability.Death");
		//React to Hit Event
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_MeleeHit, "Shared.Event.MeleeHit");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_HitReact_Light, "Shared.Event.HitReact.Light");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_HitReact_Heavy, "Shared.Event.HitReact.Heavy");
		//Damage
	UE_DEFINE_GAMEPLAY_TAG(Shared_SetByCaller_BaseDamage, "Shared.SetByCaller.BaseDamage");
		//Death Status
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Death, "Shared.Status.Death");
}
