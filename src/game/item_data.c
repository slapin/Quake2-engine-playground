/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/
#include "g_local.h"

#define DPICKUP(name)	qboolean name (edict_t * ent, edict_t * other)
#define DUSE(name)	void name (edict_t * ent, gitem_t * item)
#define DDROP(name)	void name (edict_t * ent, gitem_t * item)
#define DWEAPON(name)	void name (edict_t * ent)

DPICKUP(Pickup_Armor);
DPICKUP(Pickup_PowerArmor);
DPICKUP(Pickup_Weapon);
DPICKUP(Pickup_Ammo);
DPICKUP(Pickup_Powerup);
DPICKUP(Pickup_AncientHead);
DPICKUP(Pickup_Adrenaline);
DPICKUP(Pickup_Bandolier);
DPICKUP(Pickup_Pack);
DPICKUP(Pickup_Key);
DPICKUP(Pickup_Health);

DUSE(Use_PowerArmor);
DUSE(Use_Weapon);
DUSE(Use_Quad);
DUSE(Use_Invulnerability);
DUSE(Use_Silencer);
DUSE(Use_Breather);
DUSE(Use_Envirosuit);

DDROP(Drop_PowerArmor);
DDROP(Drop_Weapon);
DDROP(Drop_Ammo);
DDROP(Drop_General);

DWEAPON(Weapon_Blaster);
DWEAPON(Weapon_Shotgun);
DWEAPON(Weapon_SuperShotgun);
DWEAPON(Weapon_Machinegun);
DWEAPON(Weapon_Chaingun);
DWEAPON(Weapon_Grenade);
DWEAPON(Weapon_GrenadeLauncher);
DWEAPON(Weapon_RocketLauncher);
DWEAPON(Weapon_HyperBlaster);
DWEAPON(Weapon_Railgun);
DWEAPON(Weapon_BFG);

extern gitem_armor_t bodyarmor_info;
extern gitem_armor_t combatarmor_info;
extern gitem_armor_t jacketarmor_info;

static gitem_t tag_itemlist[] = {
	{NULL},	/* leave index 0 alone */

	//
	// ARMOR
	//

/*QUAKED item_armor_body (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "item_armor_body",
	 Pickup_Armor, NULL, NULL, NULL,
	 "misc/ar1_pkup.wav",
	 "models/items/armor/body/tris.md2", EF_ROTATE,
	 NULL,
/* icon */ "i_bodyarmor",
/* pickup */ "Body Armor",
/* width */ 3,
	 0,
	 NULL,
	 IT_ARMOR,
	 0,
	 &bodyarmor_info,
	 ARMOR_BODY,
/* precache */ ""
	 }
	,

/*QUAKED item_armor_combat (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "item_armor_combat",
	 Pickup_Armor,
	 NULL,
	 NULL,
	 NULL,
	 "misc/ar1_pkup.wav",
	 "models/items/armor/combat/tris.md2", EF_ROTATE,
	 NULL,
/* icon */ "i_combatarmor",
/* pickup */ "Combat Armor",
/* width */ 3,
	 0,
	 NULL,
	 IT_ARMOR,
	 0,
	 &combatarmor_info,
	 ARMOR_COMBAT,
/* precache */ ""
	 }
	,

/*QUAKED item_armor_jacket (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "item_armor_jacket",
	 Pickup_Armor,
	 NULL,
	 NULL,
	 NULL,
	 "misc/ar1_pkup.wav",
	 "models/items/armor/jacket/tris.md2", EF_ROTATE,
	 NULL,
/* icon */ "i_jacketarmor",
/* pickup */ "Jacket Armor",
/* width */ 3,
	 0,
	 NULL,
	 IT_ARMOR,
	 0,
	 &jacketarmor_info,
	 ARMOR_JACKET,
/* precache */ ""
	 }
	,

/*QUAKED item_armor_shard (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "item_armor_shard",
	 Pickup_Armor,
	 NULL,
	 NULL,
	 NULL,
	 "misc/ar2_pkup.wav",
	 "models/items/armor/shard/tris.md2", EF_ROTATE,
	 NULL,
/* icon */ "i_jacketarmor",
/* pickup */ "Armor Shard",
/* width */ 3,
	 0,
	 NULL,
	 IT_ARMOR,
	 0,
	 NULL,
	 ARMOR_SHARD,
/* precache */ ""
	 }
	,

/*QUAKED item_power_screen (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "item_power_screen",
	 Pickup_PowerArmor,
	 Use_PowerArmor,
	 Drop_PowerArmor,
	 NULL,
	 "misc/ar3_pkup.wav",
	 "models/items/armor/screen/tris.md2", EF_ROTATE,
	 NULL,
/* icon */ "i_powerscreen",
/* pickup */ "Power Screen",
/* width */ 0,
	 60,
	 NULL,
	 IT_ARMOR,
	 0,
	 NULL,
	 0,
/* precache */ ""
	 }
	,

/*QUAKED item_power_shield (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "item_power_shield",
	 Pickup_PowerArmor,
	 Use_PowerArmor,
	 Drop_PowerArmor,
	 NULL,
	 "misc/ar3_pkup.wav",
	 "models/items/armor/shield/tris.md2", EF_ROTATE,
	 NULL,
/* icon */ "i_powershield",
/* pickup */ "Power Shield",
/* width */ 0,
	 60,
	 NULL,
	 IT_ARMOR,
	 0,
	 NULL,
	 0,
/* precache */ "misc/power2.wav misc/power1.wav"
	 }
	,

	//
	// WEAPONS 
	//

/* weapon_blaster (.3 .3 1) (-16 -16 -16) (16 16 16)
always owned, never in the world
*/
	{
	 "weapon_blaster",
	 NULL,
	 Use_Weapon,
	 NULL,
	 Weapon_Blaster,
	 "misc/w_pkup.wav",
	 NULL, 0,
	 "models/weapons/v_blast/tris.md2",
/* icon */ "w_blaster",
/* pickup */ "Blaster",
	 0,
	 0,
	 NULL,
	 IT_WEAPON | IT_STAY_COOP,
	 WEAP_BLASTER,
	 NULL,
	 0,
/* precache */ "weapons/blastf1a.wav misc/lasfly.wav"
	 }
	,

/*QUAKED weapon_shotgun (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "weapon_shotgun",
	 Pickup_Weapon,
	 Use_Weapon,
	 Drop_Weapon,
	 Weapon_Shotgun,
	 "misc/w_pkup.wav",
	 "models/weapons/g_shotg/tris.md2", EF_ROTATE,
	 "models/weapons/v_shotg/tris.md2",
/* icon */ "w_shotgun",
/* pickup */ "Shotgun",
	 0,
	 1,
	 "Shells",
	 IT_WEAPON | IT_STAY_COOP,
	 WEAP_SHOTGUN,
	 NULL,
	 0,
/* precache */ "weapons/shotgf1b.wav weapons/shotgr1b.wav"
	 }
	,

/*QUAKED weapon_supershotgun (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "weapon_supershotgun",
	 Pickup_Weapon,
	 Use_Weapon,
	 Drop_Weapon,
	 Weapon_SuperShotgun,
	 "misc/w_pkup.wav",
	 "models/weapons/g_shotg2/tris.md2", EF_ROTATE,
	 "models/weapons/v_shotg2/tris.md2",
/* icon */ "w_sshotgun",
/* pickup */ "Super Shotgun",
	 0,
	 2,
	 "Shells",
	 IT_WEAPON | IT_STAY_COOP,
	 WEAP_SUPERSHOTGUN,
	 NULL,
	 0,
/* precache */ "weapons/sshotf1b.wav"
	 }
	,

/*QUAKED weapon_machinegun (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "weapon_machinegun",
	 Pickup_Weapon,
	 Use_Weapon,
	 Drop_Weapon,
	 Weapon_Machinegun,
	 "misc/w_pkup.wav",
	 "models/weapons/g_machn/tris.md2", EF_ROTATE,
	 "models/weapons/v_machn/tris.md2",
/* icon */ "w_machinegun",
/* pickup */ "Machinegun",
	 0,
	 1,
	 "Bullets",
	 IT_WEAPON | IT_STAY_COOP,
	 WEAP_MACHINEGUN,
	 NULL,
	 0,
/* precache */
	 "weapons/machgf1b.wav weapons/machgf2b.wav weapons/machgf3b.wav weapons/machgf4b.wav weapons/machgf5b.wav"}
	,

/*QUAKED weapon_chaingun (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "weapon_chaingun",
	 Pickup_Weapon,
	 Use_Weapon,
	 Drop_Weapon,
	 Weapon_Chaingun,
	 "misc/w_pkup.wav",
	 "models/weapons/g_chain/tris.md2", EF_ROTATE,
	 "models/weapons/v_chain/tris.md2",
/* icon */ "w_chaingun",
/* pickup */ "Chaingun",
	 0,
	 1,
	 "Bullets",
	 IT_WEAPON | IT_STAY_COOP,
	 WEAP_CHAINGUN,
	 NULL,
	 0,
/* precache */
	 "weapons/chngnu1a.wav weapons/chngnl1a.wav weapons/machgf3b.wav` weapons/chngnd1a.wav"}
	,

/*QUAKED ammo_grenades (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "ammo_grenades",
	 Pickup_Ammo,
	 Use_Weapon,
	 Drop_Ammo,
	 Weapon_Grenade,
	 "misc/am_pkup.wav",
	 "models/items/ammo/grenades/medium/tris.md2", 0,
	 "models/weapons/v_handgr/tris.md2",
/* icon */ "a_grenades",
/* pickup */ "Grenades",
/* width */ 3,
	 5,
	 "grenades",
	 IT_AMMO | IT_WEAPON,
	 WEAP_GRENADES,
	 NULL,
	 AMMO_GRENADES,
/* precache */
	 "weapons/hgrent1a.wav weapons/hgrena1b.wav weapons/hgrenc1b.wav weapons/hgrenb1a.wav weapons/hgrenb2a.wav "}
	,

/*QUAKED weapon_grenadelauncher (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "weapon_grenadelauncher",
	 Pickup_Weapon,
	 Use_Weapon,
	 Drop_Weapon,
	 Weapon_GrenadeLauncher,
	 "misc/w_pkup.wav",
	 "models/weapons/g_launch/tris.md2", EF_ROTATE,
	 "models/weapons/v_launch/tris.md2",
/* icon */ "w_glauncher",
/* pickup */ "Grenade Launcher",
	 0,
	 1,
	 "Grenades",
	 IT_WEAPON | IT_STAY_COOP,
	 WEAP_GRENADELAUNCHER,
	 NULL,
	 0,
/* precache */
	 "models/objects/grenade/tris.md2 weapons/grenlf1a.wav weapons/grenlr1b.wav weapons/grenlb1b.wav"}
	,

/*QUAKED weapon_rocketlauncher (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "weapon_rocketlauncher",
	 Pickup_Weapon,
	 Use_Weapon,
	 Drop_Weapon,
	 Weapon_RocketLauncher,
	 "misc/w_pkup.wav",
	 "models/weapons/g_rocket/tris.md2", EF_ROTATE,
	 "models/weapons/v_rocket/tris.md2",
/* icon */ "w_rlauncher",
/* pickup */ "Rocket Launcher",
	 0,
	 1,
	 "Rockets",
	 IT_WEAPON | IT_STAY_COOP,
	 WEAP_ROCKETLAUNCHER,
	 NULL,
	 0,
/* precache */
	 "models/objects/rocket/tris.md2 weapons/rockfly.wav weapons/rocklf1a.wav weapons/rocklr1b.wav models/objects/debris2/tris.md2"}
	,

/*QUAKED weapon_hyperblaster (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "weapon_hyperblaster",
	 Pickup_Weapon,
	 Use_Weapon,
	 Drop_Weapon,
	 Weapon_HyperBlaster,
	 "misc/w_pkup.wav",
	 "models/weapons/g_hyperb/tris.md2", EF_ROTATE,
	 "models/weapons/v_hyperb/tris.md2",
/* icon */ "w_hyperblaster",
/* pickup */ "HyperBlaster",
	 0,
	 1,
	 "Cells",
	 IT_WEAPON | IT_STAY_COOP,
	 WEAP_HYPERBLASTER,
	 NULL,
	 0,
/* precache */
	 "weapons/hyprbu1a.wav weapons/hyprbl1a.wav weapons/hyprbf1a.wav weapons/hyprbd1a.wav misc/lasfly.wav"}
	,

/*QUAKED weapon_railgun (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "weapon_railgun",
	 Pickup_Weapon,
	 Use_Weapon,
	 Drop_Weapon,
	 Weapon_Railgun,
	 "misc/w_pkup.wav",
	 "models/weapons/g_rail/tris.md2", EF_ROTATE,
	 "models/weapons/v_rail/tris.md2",
/* icon */ "w_railgun",
/* pickup */ "Railgun",
	 0,
	 1,
	 "Slugs",
	 IT_WEAPON | IT_STAY_COOP,
	 WEAP_RAILGUN,
	 NULL,
	 0,
/* precache */ "weapons/rg_hum.wav"
	 }
	,

/*QUAKED weapon_bfg (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "weapon_bfg",
	 Pickup_Weapon,
	 Use_Weapon,
	 Drop_Weapon,
	 Weapon_BFG,
	 "misc/w_pkup.wav",
	 "models/weapons/g_bfg/tris.md2", EF_ROTATE,
	 "models/weapons/v_bfg/tris.md2",
/* icon */ "w_bfg",
/* pickup */ "BFG10K",
	 0,
	 50,
	 "Cells",
	 IT_WEAPON | IT_STAY_COOP,
	 WEAP_BFG,
	 NULL,
	 0,
/* precache */
	 "sprites/s_bfg1.sp2 sprites/s_bfg2.sp2 sprites/s_bfg3.sp2 weapons/bfg__f1y.wav weapons/bfg__l1a.wav weapons/bfg__x1b.wav weapons/bfg_hum.wav"}
	,

	//
	// AMMO ITEMS
	//

/*QUAKED ammo_shells (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "ammo_shells",
	 Pickup_Ammo,
	 NULL,
	 Drop_Ammo,
	 NULL,
	 "misc/am_pkup.wav",
	 "models/items/ammo/shells/medium/tris.md2", 0,
	 NULL,
/* icon */ "a_shells",
/* pickup */ "Shells",
/* width */ 3,
	 10,
	 NULL,
	 IT_AMMO,
	 0,
	 NULL,
	 AMMO_SHELLS,
/* precache */ ""
	 }
	,

/*QUAKED ammo_bullets (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "ammo_bullets",
	 Pickup_Ammo,
	 NULL,
	 Drop_Ammo,
	 NULL,
	 "misc/am_pkup.wav",
	 "models/items/ammo/bullets/medium/tris.md2", 0,
	 NULL,
/* icon */ "a_bullets",
/* pickup */ "Bullets",
/* width */ 3,
	 50,
	 NULL,
	 IT_AMMO,
	 0,
	 NULL,
	 AMMO_BULLETS,
/* precache */ ""
	 }
	,

/*QUAKED ammo_cells (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "ammo_cells",
	 Pickup_Ammo,
	 NULL,
	 Drop_Ammo,
	 NULL,
	 "misc/am_pkup.wav",
	 "models/items/ammo/cells/medium/tris.md2", 0,
	 NULL,
/* icon */ "a_cells",
/* pickup */ "Cells",
/* width */ 3,
	 50,
	 NULL,
	 IT_AMMO,
	 0,
	 NULL,
	 AMMO_CELLS,
/* precache */ ""
	 }
	,

/*QUAKED ammo_rockets (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "ammo_rockets",
	 Pickup_Ammo,
	 NULL,
	 Drop_Ammo,
	 NULL,
	 "misc/am_pkup.wav",
	 "models/items/ammo/rockets/medium/tris.md2", 0,
	 NULL,
/* icon */ "a_rockets",
/* pickup */ "Rockets",
/* width */ 3,
	 5,
	 NULL,
	 IT_AMMO,
	 0,
	 NULL,
	 AMMO_ROCKETS,
/* precache */ ""
	 }
	,

/*QUAKED ammo_slugs (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "ammo_slugs",
	 Pickup_Ammo,
	 NULL,
	 Drop_Ammo,
	 NULL,
	 "misc/am_pkup.wav",
	 "models/items/ammo/slugs/medium/tris.md2", 0,
	 NULL,
/* icon */ "a_slugs",
/* pickup */ "Slugs",
/* width */ 3,
	 10,
	 NULL,
	 IT_AMMO,
	 0,
	 NULL,
	 AMMO_SLUGS,
/* precache */ ""
	 }
	,

	//
	// POWERUP ITEMS
	//
/*QUAKED item_quad (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "item_quad",
	 Pickup_Powerup,
	 Use_Quad,
	 Drop_General,
	 NULL,
	 "items/pkup.wav",
	 "models/items/quaddama/tris.md2", EF_ROTATE,
	 NULL,
/* icon */ "p_quad",
/* pickup */ "Quad Damage",
/* width */ 2,
	 60,
	 NULL,
	 IT_POWERUP,
	 0,
	 NULL,
	 0,
/* precache */ "items/damage.wav items/damage2.wav items/damage3.wav"
	 }
	,

/*QUAKED item_invulnerability (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "item_invulnerability",
	 Pickup_Powerup,
	 Use_Invulnerability,
	 Drop_General,
	 NULL,
	 "items/pkup.wav",
	 "models/items/invulner/tris.md2", EF_ROTATE,
	 NULL,
/* icon */ "p_invulnerability",
/* pickup */ "Invulnerability",
/* width */ 2,
	 300,
	 NULL,
	 IT_POWERUP,
	 0,
	 NULL,
	 0,
/* precache */
	 "items/protect.wav items/protect2.wav items/protect4.wav"}
	,

/*QUAKED item_silencer (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "item_silencer",
	 Pickup_Powerup,
	 Use_Silencer,
	 Drop_General,
	 NULL,
	 "items/pkup.wav",
	 "models/items/silencer/tris.md2", EF_ROTATE,
	 NULL,
/* icon */ "p_silencer",
/* pickup */ "Silencer",
/* width */ 2,
	 60,
	 NULL,
	 IT_POWERUP,
	 0,
	 NULL,
	 0,
/* precache */ ""
	 }
	,

/*QUAKED item_breather (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "item_breather",
	 Pickup_Powerup,
	 Use_Breather,
	 Drop_General,
	 NULL,
	 "items/pkup.wav",
	 "models/items/breather/tris.md2", EF_ROTATE,
	 NULL,
/* icon */ "p_rebreather",
/* pickup */ "Rebreather",
/* width */ 2,
	 60,
	 NULL,
	 IT_STAY_COOP | IT_POWERUP,
	 0,
	 NULL,
	 0,
/* precache */ "items/airout.wav"
	 }
	,

/*QUAKED item_enviro (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "item_enviro",
	 Pickup_Powerup,
	 Use_Envirosuit,
	 Drop_General,
	 NULL,
	 "items/pkup.wav",
	 "models/items/enviro/tris.md2", EF_ROTATE,
	 NULL,
/* icon */ "p_envirosuit",
/* pickup */ "Environment Suit",
/* width */ 2,
	 60,
	 NULL,
	 IT_STAY_COOP | IT_POWERUP,
	 0,
	 NULL,
	 0,
/* precache */ "items/airout.wav"
	 }
	,

/*QUAKED item_ancient_head (.3 .3 1) (-16 -16 -16) (16 16 16)
Special item that gives +2 to maximum health
*/
	{
	 "item_ancient_head",
	 Pickup_AncientHead,
	 NULL,
	 NULL,
	 NULL,
	 "items/pkup.wav",
	 "models/items/c_head/tris.md2", EF_ROTATE,
	 NULL,
/* icon */ "i_fixme",
/* pickup */ "Ancient Head",
/* width */ 2,
	 60,
	 NULL,
	 0,
	 0,
	 NULL,
	 0,
/* precache */ ""
	 }
	,

/*QUAKED item_adrenaline (.3 .3 1) (-16 -16 -16) (16 16 16)
gives +1 to maximum health
*/
	{
	 "item_adrenaline",
	 Pickup_Adrenaline,
	 NULL,
	 NULL,
	 NULL,
	 "items/pkup.wav",
	 "models/items/adrenal/tris.md2", EF_ROTATE,
	 NULL,
/* icon */ "p_adrenaline",
/* pickup */ "Adrenaline",
/* width */ 2,
	 60,
	 NULL,
	 0,
	 0,
	 NULL,
	 0,
/* precache */ ""
	 }
	,

/*QUAKED item_bandolier (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "item_bandolier",
	 Pickup_Bandolier,
	 NULL,
	 NULL,
	 NULL,
	 "items/pkup.wav",
	 "models/items/band/tris.md2", EF_ROTATE,
	 NULL,
/* icon */ "p_bandolier",
/* pickup */ "Bandolier",
/* width */ 2,
	 60,
	 NULL,
	 0,
	 0,
	 NULL,
	 0,
/* precache */ ""
	 }
	,

/*QUAKED item_pack (.3 .3 1) (-16 -16 -16) (16 16 16)
*/
	{
	 "item_pack",
	 Pickup_Pack,
	 NULL,
	 NULL,
	 NULL,
	 "items/pkup.wav",
	 "models/items/pack/tris.md2", EF_ROTATE,
	 NULL,
/* icon */ "i_pack",
/* pickup */ "Ammo Pack",
/* width */ 2,
	 180,
	 NULL,
	 0,
	 0,
	 NULL,
	 0,
/* precache */ ""
	 }
	,

	//
	// KEYS
	//
/*QUAKED key_data_cd (0 .5 .8) (-16 -16 -16) (16 16 16)
key for computer centers
*/
	{
	 "key_data_cd",
	 Pickup_Key,
	 NULL,
	 Drop_General,
	 NULL,
	 "items/pkup.wav",
	 "models/items/keys/data_cd/tris.md2", EF_ROTATE,
	 NULL,
	 "k_datacd",
	 "Data CD",
	 2,
	 0,
	 NULL,
	 IT_STAY_COOP | IT_KEY,
	 0,
	 NULL,
	 0,
/* precache */ ""
	 }
	,

/*QUAKED key_power_cube (0 .5 .8) (-16 -16 -16) (16 16 16) TRIGGER_SPAWN NO_TOUCH
warehouse circuits
*/
	{
	 "key_power_cube",
	 Pickup_Key,
	 NULL,
	 Drop_General,
	 NULL,
	 "items/pkup.wav",
	 "models/items/keys/power/tris.md2", EF_ROTATE,
	 NULL,
	 "k_powercube",
	 "Power Cube",
	 2,
	 0,
	 NULL,
	 IT_STAY_COOP | IT_KEY,
	 0,
	 NULL,
	 0,
/* precache */ ""
	 }
	,

/*QUAKED key_pyramid (0 .5 .8) (-16 -16 -16) (16 16 16)
key for the entrance of jail3
*/
	{
	 "key_pyramid",
	 Pickup_Key,
	 NULL,
	 Drop_General,
	 NULL,
	 "items/pkup.wav",
	 "models/items/keys/pyramid/tris.md2", EF_ROTATE,
	 NULL,
	 "k_pyramid",
	 "Pyramid Key",
	 2,
	 0,
	 NULL,
	 IT_STAY_COOP | IT_KEY,
	 0,
	 NULL,
	 0,
/* precache */ ""
	 }
	,

/*QUAKED key_data_spinner (0 .5 .8) (-16 -16 -16) (16 16 16)
key for the city computer
*/
	{
	 "key_data_spinner",
	 Pickup_Key,
	 NULL,
	 Drop_General,
	 NULL,
	 "items/pkup.wav",
	 "models/items/keys/spinner/tris.md2", EF_ROTATE,
	 NULL,
	 "k_dataspin",
	 "Data Spinner",
	 2,
	 0,
	 NULL,
	 IT_STAY_COOP | IT_KEY,
	 0,
	 NULL,
	 0,
/* precache */ ""
	 }
	,

/*QUAKED key_pass (0 .5 .8) (-16 -16 -16) (16 16 16)
security pass for the security level
*/
	{
	 "key_pass",
	 Pickup_Key,
	 NULL,
	 Drop_General,
	 NULL,
	 "items/pkup.wav",
	 "models/items/keys/pass/tris.md2", EF_ROTATE,
	 NULL,
	 "k_security",
	 "Security Pass",
	 2,
	 0,
	 NULL,
	 IT_STAY_COOP | IT_KEY,
	 0,
	 NULL,
	 0,
/* precache */ ""
	 }
	,

/*QUAKED key_blue_key (0 .5 .8) (-16 -16 -16) (16 16 16)
normal door key - blue
*/
	{
	 "key_blue_key",
	 Pickup_Key,
	 NULL,
	 Drop_General,
	 NULL,
	 "items/pkup.wav",
	 "models/items/keys/key/tris.md2", EF_ROTATE,
	 NULL,
	 "k_bluekey",
	 "Blue Key",
	 2,
	 0,
	 NULL,
	 IT_STAY_COOP | IT_KEY,
	 0,
	 NULL,
	 0,
/* precache */ ""
	 }
	,

/*QUAKED key_red_key (0 .5 .8) (-16 -16 -16) (16 16 16)
normal door key - red
*/
	{
	 "key_red_key",
	 Pickup_Key,
	 NULL,
	 Drop_General,
	 NULL,
	 "items/pkup.wav",
	 "models/items/keys/red_key/tris.md2", EF_ROTATE,
	 NULL,
	 "k_redkey",
	 "Red Key",
	 2,
	 0,
	 NULL,
	 IT_STAY_COOP | IT_KEY,
	 0,
	 NULL,
	 0,
/* precache */ ""
	 }
	,

/*QUAKED key_commander_head (0 .5 .8) (-16 -16 -16) (16 16 16)
tank commander's head
*/
	{
	 "key_commander_head",
	 Pickup_Key,
	 NULL,
	 Drop_General,
	 NULL,
	 "items/pkup.wav",
	 "models/monsters/commandr/head/tris.md2", EF_GIB,
	 NULL,
/* icon */ "k_comhead",
/* pickup */ "Commander's Head",
/* width */ 2,
	 0,
	 NULL,
	 IT_STAY_COOP | IT_KEY,
	 0,
	 NULL,
	 0,
/* precache */ ""
	 }
	,

/*QUAKED key_airstrike_target (0 .5 .8) (-16 -16 -16) (16 16 16)
tank commander's head
*/
	{
	 "key_airstrike_target",
	 Pickup_Key,
	 NULL,
	 Drop_General,
	 NULL,
	 "items/pkup.wav",
	 "models/items/keys/target/tris.md2", EF_ROTATE,
	 NULL,
/* icon */ "i_airstrike",
/* pickup */ "Airstrike Marker",
/* width */ 2,
	 0,
	 NULL,
	 IT_STAY_COOP | IT_KEY,
	 0,
	 NULL,
	 0,
/* precache */ ""
	 }
	,

	{
	 NULL,
	 Pickup_Health,
	 NULL,
	 NULL,
	 NULL,
	 "items/pkup.wav",
	 NULL, 0,
	 NULL,
/* icon */ "i_health",
/* pickup */ "Health",
/* width */ 3,
	 0,
	 NULL,
	 0,
	 0,
	 NULL,
	 0,
/* precache */
	 "items/s_health.wav items/n_health.wav items/l_health.wav items/m_health.wav"}
	,

	// end of list marker
	{NULL}
};
gitem_t *itemlist = tag_itemlist;

