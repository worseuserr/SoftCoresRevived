#include "SoftCores/Mod/NerfedSleepAndBath.h"

using namespace SoftCores;

NerfedSleepAndBath::NerfedSleepAndBath(ModContext *context)
	: Feature(context) {}


// if (sleepStaminaOnly)
// 		{
// 			bool isNotinControl;
// 			bool isSleeping;
//
// 			isSleeping = false;
// 			isNotinControl = false;
// 			if (!PLR.IsInControl() && !isNotinControl) // get last health and deadeye core values when player is no longer in control (when using campfire from wheel or start of most scenario)
// 			{
// 				isNotinControl = true;
// 				lastHealthCore = PLR.GetCore(Core::Health);
// 				lastDeadEyeCore = PLR.GetCore(Core::DeadEye);
// 			}
// 			else if (PLR.IsInControl() && isNotinControl) // set back to false when player regain control
// 			{
// 				isNotinControl = false;
// 			}
//
// 			if (isNotinControl && PLR.IsInSleepScenario() && !isSleeping) // once hooked the first entry point of scenario which is -1 while not in control, stop hooking at all
// 			{
// 				isSleeping = true;
// 				stringstream text;
// 				text << "hooked player is sleeping while not in control, lastHealthCore: " << lastHealthCore << " lastDeadEyeCore: " << lastDeadEyeCore;
// 				LOGGER.Write(text.str().c_str());
// 			}
// 			else if (!isNotinControl && PLR.IsInSleepScenario() && !isSleeping) // once hooked the first entry point of scenario which is -1 while in control, stop hooking at all
// 			{
// 				isSleeping = true;
// 				lastHealthCore = PLR.GetCore(Core::Health);
// 				lastDeadEyeCore = PLR.GetCore(Core::DeadEye);
// 				stringstream text;
// 				text << "hooked player is sleeping while in control, lastHealthCore: " << lastHealthCore << " lastDeadEyeCore: " << lastDeadEyeCore;
// 				LOGGER.Write(text.str().c_str());
// 			}
// 			else if (World::IsRaining() && PED::_IS_PED_USING_SCENARIO_HASH(playerPed, Keys::GetHash("PROP_PLAYER_SLEEP_TENT_A_FRAME")) && !isSleeping) // if player sets camp when its raining, will go directly to tent, hence not initiating -1 scenario point i reckon
// 			{
// 				isSleeping = true;
// 				lastHealthCore = PLR.GetCore(Core::Health);
// 				lastDeadEyeCore = PLR.GetCore(Core::DeadEye);
// 				stringstream text;
// 				text << "hooked player is sleeping while raining, lastHealthCore: " << lastHealthCore << " lastDeadEyeCore: " << lastDeadEyeCore;
// 				LOGGER.Write(text.str().c_str());
// 			}
//
// 			if (isSleeping) // keep setting player last health, deadeye until player starts moving or using campfire scenario
// 			{
// 				PLR.SetCore(Core::Health, lastHealthCore);
// 				PLR.SetCore(Core::DeadEye, lastDeadEyeCore);
// 			}
// 		}
// 		// END OF SLEEP STAMINA ONLY PART +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// 		// START OF BATH DEADEYE ONLY PART ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		if (bathDeadEyeOnly)
// 		{
// 			static bool isBathing = false;
//
// 			if (PLR.IsBathing() && !isBathing) // hook bath here & get last health, stamina core
// 			{
// 				lastHealthCore = PLR.GetCore(Core::Health);
// 				lastStaminaCore = PLR.GetCore(Core::Stamina);
// 				isBathing = true;
// 				stringstream text;
// 				text << "hooked player is bathing, lastHealthCore: " << lastHealthCore << " lastStaminaCore: " << lastStaminaCore;
// 				LOGGER.Write(text.str().c_str());
// 			}
//
// 			if (isBathing) // keep setting player last health, stamina until player starts moving
// 			{
// 				PLR.SetCore(Core::Health, lastHealthCore);
// 				PLR.SetCore(Core::Stamina, lastStaminaCore);
//
// 				isBathing = (PLR.IsMoving()) ? false : true;
// 			}
// 		}
