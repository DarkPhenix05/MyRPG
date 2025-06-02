// KasaiRaito Studios All Rights Reserved

#include "WarriorGameplayTags.h"

namespace  WarriorGameplayTags
{
	/** INPUT TAGS **/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "Input.Move" );
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "Input.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipAxe, "Input.EquipAxe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipAxe, "Input.UnequipAxe");

	/** Player TAGS **/
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe, "Player.Weapon.Axe");
	
	UE_DEFINE_GAMEPLAY_TAG(Player_Events_Equip_Axe, "Player.Event.Equip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Events_Unequip_Axe, "Player.Event.Unequip.Axe");
}
