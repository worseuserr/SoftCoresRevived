#include "SoftCores/Mod/NoDeadeyeReload.h"

using namespace SoftCores;

void NoDeadeyeReload::Initialize()
{

}

// START OF DEADEYE NO RELOAD PART ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		if (!deadEyeReload)
// 		{
// 			if (WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &primaryWeapon, false, 0, true)) // primary hand and ammo
// 			{
// 				primaryClipSize = WEAPON::GET_MAX_AMMO_IN_CLIP(playerPed, primaryWeapon, true);
// 				WEAPON::GET_AMMO_IN_CLIP(playerPed, currPrimaryAmmo, primaryWeapon);
// 			}
//
// 			if (WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &secondaryWeapon, false, 1, true)) // secondary hand weapon and ammo
// 			{
// 				secondaryClipSize = WEAPON::GET_MAX_AMMO_IN_CLIP(playerPed, secondaryWeapon, true);
// 				WEAPON::GET_AMMO_IN_CLIP(playerPed, currSecondaryAmmo, secondaryWeapon);
// 			}
//
// 			if (PED::IS_PED_SHOOTING(playerPed) || PED::GET_PED_RESET_FLAG(playerPed, 332) || PED::IS_PED_RELOADING(playerPed)) // updates the value ammoUsed everytime player shoots, switched weapon or reloading
// 			{
// 				primaryAmmoUsed = primaryClipSize - *currPrimaryAmmo;
// 				secondaryAmmoUsed = secondaryClipSize - *currSecondaryAmmo;
// 				primaryAmmoLeft = primaryClipSize - primaryAmmoUsed;
// 				secondaryAmmoLeft = secondaryClipSize - secondaryAmmoUsed;
// 			}
//
// 			if (PLR.IsDeadeyeActivated() && !TASK::_IS_PED_DUELLING(playerPed)) // hook deadEye and sets ammo accordingly and let game handle dueling
// 			{
// 				WEAPON::SET_AMMO_IN_CLIP(playerPed, primaryWeapon, primaryAmmoLeft);
// 				WEAPON::SET_AMMO_IN_CLIP(playerPed, secondaryWeapon, secondaryAmmoLeft);
// 			}
// 		}
// 		// END OF DEADEYE NO RELOAD PART ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
