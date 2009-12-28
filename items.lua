fooarray = {
	{
		classname = nil,
	},
	{
		classname = "item_armor_body",
		pickup = "Pickup_Armor",
		use = nil,
		drop = nil,
		weaponthink = nil,
		pickup_sound = "misc/ar1_pkup.wav",
		world_model = "models/items/armor/body/tris.md2",
		world_model_flags = EF_ROTATE,
		view_model = nil,
		icon = "i_bodyarmor",
		pickup_name = "Body Armor", -- for printing on pickup
		count_width = 3, -- number of digits to display by icon
		quantity = 0, -- for ammo how much, for weapons how much is used per shot
		ammo = nil, -- for weapons
		flags = IT_ARMOR, -- IT_* flags
		weapmodel = 0,
		info = "bodyarmor_info", -- TODO should be userdata
		tag = ARMOR_BODY,
		precaches = "",
	},
	{
		classname = "item_armor_combat",
		pickup = "Pickup_Armor",
		use = nil,
		drop = nil,
		weaponthink = nil,
		pickup_sound = "misc/ar1_pkup.wav",
		world_model = "models/items/armor/combat/tris.md2",
		world_model_flags = EF_ROTATE,
		view_model = nil,
		icon = "i_combatarmor",
		pickup_name = "Combat Armor", -- for printing on pickup
		count_width = 3, -- number of digits to display by icon
		quantity = 0, -- for ammo how much, for weapons how much is used per shot
		ammo = nil, -- for weapons
		flags = IT_ARMOR, -- IT_* flags
		weapmodel = 0,
		info = "combatarmor_info", -- TODO should be userdata
		tag = ARMOR_COMBAT,
		precaches = "",
	},
	{
		classname = "item_armor_jacket",
		pickup = "Pickup_Armor",
		use = nil,
		drop = nil,
		weaponthink = nil,
		pickup_sound = "misc/ar1_pkup.wav",
		world_model = "models/items/armor/jacket/tris.md2",
		world_model_flags = EF_ROTATE,
		view_model = nil,
		icon = "i_jacketarmor",
		pickup_name = "Jacket Armor", -- for printing on pickup
		count_width = 3, -- number of digits to display by icon
		quantity = 0, -- for ammo how much, for weapons how much is used per shot
		ammo = nil, -- for weapons
		flags = IT_ARMOR, -- IT_* flags
		weapmodel = 0,
		info = "jacketarmor_info", -- TODO should be userdata
		tag = ARMOR_JACKET,
		precaches = "",
	},
	{
		classname = "item_armor_shard",
		pickup = "Pickup_Armor",
		use = nil,
		drop = nil,
		weaponthink = nil,
		pickup_sound = "misc/ar1_pkup.wav",
		world_model = "models/items/armor/shard/tris.md2",
		world_model_flags = EF_ROTATE,
		view_model = nil,
		icon = "i_jacketarmor",
		pickup_name = "Armor Shard", -- for printing on pickup
		count_width = 3, -- number of digits to display by icon
		quantity = 0, -- for ammo how much, for weapons how much is used per shot
		ammo = nil, -- for weapons
		flags = IT_ARMOR, -- IT_* flags
		weapmodel = 0,
		info = nil, -- TODO should be userdata
		tag = ARMOR_SHARD,
		precaches = "",
	},
}

for k, v in ipairs(fooarray) do
	print(v.pickup_name)
end

