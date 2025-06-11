// KasaiRaito Studios All Rights Reserved

#include "WarriorGameplayTags.h"

namespace  WarriorGameplayTags
{
	/** INPUT TAGS **/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "Input.Move" );
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "Input.Look");
	
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipAxe, "Input.EquipAxe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipAxe, "Input.UnequipAxe");
	
	UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack_Axe, "Input.LightAttack.Axe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_HeavyAttack_Axe, "Input.HeavyAttack.Axe");

	/** Player TAGS **/
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Axe, "Player.Ability.Equip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip_Axe, "Player.Ability.Unequip.Axe");
	
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light_Axe, "Player.Ability.Attack.Light.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Heavy_Axe, "Player.Ability.Attack.Heavy.Axe");
	
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe, "Player.Weapon.Axe");
	
	UE_DEFINE_GAMEPLAY_TAG(Player_Events_Equip_Axe, "Player.Event.Equip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Events_Unequip_Axe, "Player.Event.Unequip.Axe");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_JumpToFinisher, "Player.Status.JumpToFinisher");	

	/** Enemy TAGS **/
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon, "Enemy.Weapon")

	/** Shared TAGS **/
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_MeleeHit, "Shared.Event.MeleeHit")
	UE_DEFINE_GAMEPLAY_TAG(Shared_SetByCaller_BaseDamage, "Shared.SetByCaller.BaseDamage")
}
