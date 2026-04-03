#include <sstream>
#include <map>
#include <SoftCores/Keys.h>
#include <string>
#include <Windows.h>
#include "Script.h"
#include <chrono>
#include <SoftCores/Util/Logger.h>
#include <SoftCores/Util/File.h>
#include <SoftCores/Config.h>
#include "SoftCores/Tick.h"
#include "SoftCores/Mod/Mod.h"

using namespace std;
using namespace SoftCores;
using namespace SoftCores::Util;

const char *const		LOG_FILE = ".\\SoftCoresRevived.log";
const wchar_t *const	INI_FILE = L".\\SoftCoresRevived.ini";

// TODO: error handling

// currently unused
//static void showSubtitle(const char* text)
//{
//	UILOG::_UILOG_SET_CACHED_OBJECTIVE((const char*)MISC::_CREATE_VAR_STRING(10, "LITERAL_STRING", text)); //
//	UILOG::_UILOG_PRINT_CACHED_OBJECTIVE(); // _UILOG_PRINT_CACHED_OBJECTIVE
//	UILOG::_UILOG_CLEAR_CACHED_OBJECTIVE(); //
//}


void ScriptMain()
{
	Logger		logger(LOG_FILE);

	logger.Write("### Original SoftCores Mod by opsedar ###");
	logger.Write("### Revived by worseuserr ###");
	logger.Write(File::Exists(File::WideToUTF8(INI_FILE).c_str())
		? "### ini found ###"
		: "#!# ini not found #!#");
	const std::unique_ptr<Config>	config = std::make_unique<Config>(INI_FILE, logger);
	const std::unique_ptr<Mod>		mod = std::make_unique<Mod>(&logger, config.get());

	// Set random seed.
	srand(static_cast<int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
	logger.Write("### Initializing mod loop ###");
	// Mod ends on Tick::StopLoop();
	Tick::StartLoop();
	logger.Write("### Mod loop ended ###");
	logger.Write("### Freeing memory ###");
}

//
// int oldmain()
// {
// 	bool enableLogging = GetPrivateProfileInt("DEBUG", "ENABLE_LOGGING", 0, ".\\SoftCores.ini");
// 	if (enableLogging)
// 	{
// 		LOGGER.Write("### SoftCores Mod by opsedar ###");
// 		LOGGER.Write("### Reworked by worseuserr ###");
// 		LOGGER.Write(File::Exists(".\\SoftCores.ini") ? "### SoftCores.ini found ###" : "### SoftCores.ini not found ###");
// 	}
//
// 	// immersion
// 	bool immersionFX = GetPrivateProfileInt("IMMERSION", "IMMERSION_FX", 1, ".\\SoftCores.ini");
// 	bool emptyHealthFX = GetPrivateProfileInt("IMMERSION", "EMPTY_HEALTH_FX", 1, ".\\SoftCores.ini");
// 	bool emptyStaminaFX = GetPrivateProfileInt("IMMERSION", "EMPTY_STAMINA_FX", 1, ".\\SoftCores.ini");
// 	bool emptyDeadEyeFX = GetPrivateProfileInt("IMMERSION", "EMPTY_DEADEYE_FX", 1, ".\\SoftCores.ini");
// 	bool overpowerFX = GetPrivateProfileInt("IMMERSION", "OVERPOWER_FX", 1, ".\\SoftCores.ini");
// 	bool duelFX = GetPrivateProfileInt("IMMERSION", "DUEL_FX", 1, ".\\SoftCores.ini");
// 	bool deadEyeFX = GetPrivateProfileInt("IMMERSION", "DEADEYE_FX", 1, ".\\SoftCores.ini");
// 	bool eagleEyeFX = GetPrivateProfileInt("IMMERSION", "EAGLEEYE_FX", 1, ".\\SoftCores.ini");
// 	bool hudWheelFX = GetPrivateProfileInt("IMMERSION", "HUDWHEEL_FX", 0, ".\\SoftCores.ini");
// 	bool killCamFX = GetPrivateProfileInt("IMMERSION", "KILLCAM_FX", 0, ".\\SoftCores.ini");
// 	bool pedKillFX = GetPrivateProfileInt("IMMERSION", "PEDKILL_FX", 0, ".\\SoftCores.ini");
// 	bool deathFX = GetPrivateProfileInt("IMMERSION", "DEATH_FX", 0, ".\\SoftCores.ini");
// 	bool failFX = GetPrivateProfileInt("IMMERSION", "FAIL_FX", 0, ".\\SoftCores.ini");
//
// 	bool pickupsGlow = GetPrivateProfileInt("IMMERSION", "PICKUPS_GLOW", 0, ".\\SoftCores.ini");
// 	bool objectsGlow = GetPrivateProfileInt("IMMERSION", "OBJECTS_GLOW", 0, ".\\SoftCores.ini");
// 	bool hostileBlip = GetPrivateProfileInt("IMMERSION", "HOSTILE_BLIP", 0, ".\\SoftCores.ini");
// 	bool hostileBlipOnMission = GetPrivateProfileInt("IMMERSION", "HOSTILE_BLIP_ON_MISSION", 0, ".\\SoftCores.ini");
// 	bool deadEyeReload = GetPrivateProfileInt("IMMERSION", "DEADEYE_RELOAD", 0, ".\\SoftCores.ini");
// 	bool sleepStaminaOnly = GetPrivateProfileInt("IMMERSION", "SLEEP_STAMINA_ONLY", 1, ".\\SoftCores.ini");
// 	bool bathDeadEyeOnly = GetPrivateProfileInt("IMMERSION", "BATH_DEADEYE_ONLY", 1, ".\\SoftCores.ini");
// 	bool headshotImmunity = GetPrivateProfileInt("IMMERSION", "HEADSHOT_IMMUNITY", 0, ".\\SoftCores.ini");
//
// 	// dead eye no reload usage
// 	Ped playerPed = PLAYER::PLAYER_PED_ID();
//
// 	Hash primaryWeapon;
// 	Hash secondaryWeapon;
//
// 	WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &primaryWeapon, false, 0, true);
// 	WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &secondaryWeapon, false, 1, true);
//
// 	int primaryAmmo{};
// 	int secondaryAmmo{};
// 	int* currPrimaryAmmo = &primaryAmmo;
// 	int* currSecondaryAmmo = &secondaryAmmo;
// 	int primaryClipSize = WEAPON::GET_MAX_AMMO_IN_CLIP(playerPed, primaryWeapon, true);
// 	int secondaryClipSize = WEAPON::GET_MAX_AMMO_IN_CLIP(playerPed, secondaryWeapon, true);
// 	WEAPON::GET_AMMO_IN_CLIP(playerPed, currPrimaryAmmo, primaryWeapon);
// 	WEAPON::GET_AMMO_IN_CLIP(playerPed, currSecondaryAmmo, secondaryWeapon);
// 	int primaryAmmoUsed = primaryClipSize - *currPrimaryAmmo;
// 	int secondaryAmmoUsed = secondaryClipSize - *currSecondaryAmmo;
// 	int primaryAmmoLeft = primaryClipSize - primaryAmmoUsed;
// 	int secondaryAmmoLeft = primaryClipSize - secondaryAmmoUsed;
//
// 	// timers
// 	int depletionMs = GetPrivateProfileInt("TIMERS", "CORE_DEPLETION", 120000, ".\\SoftCores.ini");
// 	int healthMs = GetPrivateProfileInt("TIMERS", "HEALTH_PENALTY", 8000, ".\\SoftCores.ini");
// 	unsigned int temperatureMs = GetPrivateProfileInt("TIMERS", "TEMPERATURE_PENALTY", 8000, ".\\SoftCores.ini");
// 	int aiHealMs = GetPrivateProfileInt("TIMERS", "AI_HEALTH_REGEN", 5000, ".\\SoftCores.ini");
// 	int aimMs = GetPrivateProfileInt("TIMERS", "AIMING_DEPLETION", 500, ".\\SoftCores.ini");
//
// 	int depletionTimer = World::GetGameTimer() + depletionMs;
// 	int healthTimer = World::GetGameTimer() + healthMs;
// 	unsigned int temperatureTimer = World::GetGameTimer() + temperatureMs;
// 	int aimTimer = World::GetGameTimer() + aimMs;
//
// 	// core modifiers
// 	bool isPlaying{};
// 	bool temperatureCore = GetPrivateProfileInt("TEMPERATURE_MODIFIER", "TEMPERATURE_CORE", 1, ".\\SoftCores.ini");
// 	bool temperatureCoreFx = GetPrivateProfileInt("TEMPERATURE_MODIFIER", "TEMPERATURE_CORE_FX", 1, ".\\SoftCores.ini");
// 	bool temperatureCoreSprite = GetPrivateProfileInt("TEMPERATURE_MODIFIER", "TEMPERATURE_CORE_SPRITE", 1, ".\\SoftCores.ini");
// 	bool aimPenalty = GetPrivateProfileInt("CORE_MODIFIER", "AIM_PENALTY", 1, ".\\SoftCores.ini");
//
// 	int playerHpModifier = GetPrivateProfileInt("CORE_MODIFIER", "PLAYER_HEALTH_CORE", 4, ".\\SoftCores.ini");
// 	int playerStModifier = GetPrivateProfileInt("CORE_MODIFIER", "PLAYER_STAMINA_CORE", 12, ".\\SoftCores.ini");
// 	int playerDeModifier = GetPrivateProfileInt("CORE_MODIFIER", "PLAYER_DEADEYE_CORE", 8, ".\\SoftCores.ini");
// 	int horseHpModifier = GetPrivateProfileInt("CORE_MODIFIER", "HORSE_HEALTH_CORE", 4, ".\\SoftCores.ini");
// 	int horseStModifier = GetPrivateProfileInt("CORE_MODIFIER", "HORSE_STAMINA_CORE", 8, ".\\SoftCores.ini");
//
// 	// death stuffs
// 	bool isInMission{};
// 	bool penaltyOnDeath = GetPrivateProfileInt("DEATH_PENALTY", "PENALTY_ON_DEATH", 1, ".\\SoftCores.ini");
// 	bool loseHandWeapon = GetPrivateProfileInt("DEATH_PENALTY", "LOSE_HAND_WEAPON", 1, ".\\SoftCores.ini");
// 	bool loseBodyWeapon = GetPrivateProfileInt("DEATH_PENALTY", "LOSE_BODY_WEAPON", 1, ".\\SoftCores.ini");
// 	bool loseExoticWeapon = GetPrivateProfileInt("DEATH_PENALTY", "LOSE_EXOTIC_WEAPON", 1, ".\\SoftCores.ini");
//
// 	// lose randomized % of money on death
// 	bool loseMoney = GetPrivateProfileInt("DEATH_PENALTY", "LOSE_MONEY", 1, ".\\SoftCores.ini");
// 	int lowestMoneyLose = GetPrivateProfileInt("DEATH_PENALTY", "LOWEST_MONEY_LOSE", 40, ".\\SoftCores.ini");
// 	int highestMoneyLose = GetPrivateProfileInt("DEATH_PENALTY", "HIGHEST_MONEY_LOSE", 80, ".\\SoftCores.ini");
//
// 	// used for restoring only stamina after sleep and deadeye after bath
// 	int lastHealthCore{};
// 	int lastStaminaCore{};
// 	int lastDeadEyeCore{};
//
// 	// damage modifier
// 	bool damageTweaks = GetPrivateProfileInt("DAMAGE_MODIFIER", "DAMAGE_TWEAKS", 1, ".\\SoftCores.ini");
// 	float aiDamageHighest = (float)GetPrivateProfileInt("DAMAGE_MODIFIER", "HIGHEST_AI_DAMAGE", 500, ".\\SoftCores.ini") / 100;
// 	float aiDamageHigh = (float)GetPrivateProfileInt("DAMAGE_MODIFIER", "HIGH_AI_DAMAGE", 400, ".\\SoftCores.ini") / 100;
// 	float aiDamageMedium = (float)GetPrivateProfileInt("DAMAGE_MODIFIER", "MEDIUM_AI_DAMAGE", 300, ".\\SoftCores.ini") / 100;
// 	float aiDamageLow = (float)GetPrivateProfileInt("DAMAGE_MODIFIER", "LOW_AI_DAMAGE", 200, ".\\SoftCores.ini") / 100;
// 	float aiDamageLowest = (float)GetPrivateProfileInt("DAMAGE_MODIFIER", "LOWEST_AI_DAMAGE", 100, ".\\SoftCores.ini") / 100;
//
// 	float playerDamageHighest = (float)GetPrivateProfileInt("DAMAGE_MODIFIER", "HIGHEST_PLAYER_DAMAGE", 120, ".\\SoftCores.ini") / 100;
// 	float playerDamageHigh = (float)GetPrivateProfileInt("DAMAGE_MODIFIER", "HIGH_PLAYER_DAMAGE", 100, ".\\SoftCores.ini") / 100;
// 	float playerDamageMedium = (float)GetPrivateProfileInt("DAMAGE_MODIFIER", "MEDIUM_PLAYER_DAMAGE", 80, ".\\SoftCores.ini") / 100;
// 	float playerDamageLow = (float)GetPrivateProfileInt("DAMAGE_MODIFIER", "LOW_PLAYER_DAMAGE", 60, ".\\SoftCores.ini") / 100;
// 	float playerDamageLowest = (float)GetPrivateProfileInt("DAMAGE_MODIFIER", "LOWEST_PLAYER_DAMAGE", 40, ".\\SoftCores.ini") / 100;
//
// 	// ai regen and heal map
// 	std::map<Ped, int> aiRegenMap;
// 	std::map<Ped, int> aiHealMap;
//
// 	// hostile blip map
// 	std::map<Ped, Blip> hostileBlipMap;
//
// 	// ai combat modifier variables
// 	bool aiTweaks = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "AI_TWEAKS", 1, ".\\SoftCores.ini");
// 	bool aiRegen = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "AI_REGEN", 1, ".\\SoftCores.ini");
// 	//int aiHighestRegen = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "HIGHEST_HEALTH_REGEN", 80, ".\\SoftCores.ini");
// 	int aiHighRegen = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "HIGH_HEALTH_REGEN", 60, ".\\SoftCores.ini");
// 	int aiMediumRegen = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "MEDIUM_HEALTH_REGEN", 40, ".\\SoftCores.ini");
// 	int aiLowRegen = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "LOW_HEALTH_REGEN", 20, ".\\SoftCores.ini");
// 	int aiLowestRegen = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "LOWEST_HEALTH_REGEN", 10, ".\\SoftCores.ini");
//
// 	bool aiAccuracy = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "AI_ACCURACY", 1, ".\\SoftCores.ini");
// 	int aiHighestAccuracy = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "HIGHEST_ACCURACY", 100, ".\\SoftCores.ini");
// 	int aiHighAccuracy = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "HIGH_ACCURACY", 90, ".\\SoftCores.ini");
// 	int aiMediumAccuracy = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "MEDIUM_ACCURACY", 80, ".\\SoftCores.ini");
// 	int aiLowAccuracy = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "LOW_ACCURACY", 70, ".\\SoftCores.ini");
// 	int aiLowestAccuracy = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "LOWEST_ACCURACY", 60, ".\\SoftCores.ini");
//
// 	bool aiShootRate = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "AI_SHOOT_RATE", 1, ".\\SoftCores.ini");
// 	int aiHighestShootRate = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "HIGHEST_SHOOTRATE", 1000, ".\\SoftCores.ini");
// 	int aiHighShootRate = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "HIGH_SHOOTRATE", 900, ".\\SoftCores.ini");
// 	int aiMediumShootRate = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "MEDIUM_SHOOTRATE", 800, ".\\SoftCores.ini");
// 	int aiLowShootRate = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "LOW_SHOOTRATE", 700, ".\\SoftCores.ini");
// 	int aiLowestShootRate = GetPrivateProfileInt("AI_COMBAT_MODIFIER", "LOWEST_SHOOTRATE", 600, ".\\SoftCores.ini");
//
// 	// mod range
// 	int pedsRange = GetPrivateProfileInt("MOD_RANGE", "PEDS", 1024, ".\\SoftCores.ini");
//
// 	// prompt creation here
// 	int radarPromptGroup = 704572841;
// 	int hatPrompt = HUD::_UIPROMPT_REGISTER_BEGIN();
// 	if (PAD::_IS_USING_KEYBOARD(0)) HUD::_UIPROMPT_SET_CONTROL_ACTION(hatPrompt, Keys::GetHash("INPUT_INTERACT_OPTION2"));
// 	else if (!PAD::_IS_USING_KEYBOARD(0)) HUD::_UIPROMPT_SET_CONTROL_ACTION(hatPrompt, Keys::GetHash("INPUT_SPRINT"));
// 	HUD::_UIPROMPT_SET_TEXT(hatPrompt, MISC::_CREATE_VAR_STRING(10, "LITERAL_STRING", "unequip hat"));
// 	HUD::_UIPROMPT_SET_STANDARD_MODE(hatPrompt, 1);
// 	HUD::_UIPROMPT_REGISTER_END(hatPrompt);
// 	HUD::_UIPROMPT_SET_GROUP(hatPrompt, radarPromptGroup, 0);
// 	UI::TogglePrompt(hatPrompt, false, false);
//
// 	int glovePrompt = HUD::_UIPROMPT_REGISTER_BEGIN(); // prompt for cinematic camera
// 	if (PAD::_IS_USING_KEYBOARD(0)) HUD::_UIPROMPT_SET_CONTROL_ACTION(glovePrompt, Keys::GetHash("INPUT_INTERACT_OPTION1"));
// 	else if (!PAD::_IS_USING_KEYBOARD(0)) HUD::_UIPROMPT_SET_CONTROL_ACTION(glovePrompt, Keys::GetHash("INPUT_LOOK_BEHIND"));
// 	HUD::_UIPROMPT_SET_TEXT(glovePrompt, MISC::_CREATE_VAR_STRING(10, "LITERAL_STRING", "unequip gloves"));
// 	HUD::_UIPROMPT_SET_STANDARD_MODE(glovePrompt, 1);
// 	HUD::_UIPROMPT_REGISTER_END(glovePrompt);
// 	HUD::_UIPROMPT_SET_GROUP(glovePrompt, radarPromptGroup, 0);
// 	UI::TogglePrompt(glovePrompt, false, false);
//
// 	while (true)
// 	{
// 		// variables that need constantly updated
// 		Player playerID = PLAYER::PLAYER_ID();
// 		playerPed = PLAYER::PLAYER_PED_ID();
// 		Ped horsePed = PLAYER::_GET_SADDLE_HORSE_FOR_PLAYER(playerID);
//
// 		// IMMERSION PART =======================================================================================================================
//
// 		// START IMMERSION FX +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		if (immersionFX)
// 		{
// 			if (!emptyHealthFX) GRAPHICS::ANIMPOSTFX_STOP("PlayerRPGEmptyCoreHealth");
// 			if (!emptyStaminaFX) GRAPHICS::ANIMPOSTFX_STOP("PlayerRPGEmptyCoreStamina");
// 			if (!emptyDeadEyeFX) GRAPHICS::ANIMPOSTFX_STOP("PlayerRPGEmptyCoreDeadEye");
// 			if (!overpowerFX) GRAPHICS::ANIMPOSTFX_STOP("PlayerOverpower");
// 			if (!duelFX) GRAPHICS::ANIMPOSTFX_STOP("Duel");
// 			if (!deadEyeFX) GRAPHICS::ANIMPOSTFX_STOP("deadeye");
// 			if (!deadEyeFX) GRAPHICS::ANIMPOSTFX_STOP("DeadEyeEmpty");
// 			if (!eagleEyeFX) GRAPHICS::ANIMPOSTFX_STOP("EagleEye");
// 			if (!hudWheelFX) GRAPHICS::ANIMPOSTFX_STOP("WheelHUDIn");
// 			if (!killCamFX) GRAPHICS::ANIMPOSTFX_STOP("killCam");
// 			if (!killCamFX) GRAPHICS::ANIMPOSTFX_STOP("KillCamHonorChange");
// 			if (!pedKillFX) GRAPHICS::ANIMPOSTFX_STOP("PedKill");
// 			if (!deathFX) GRAPHICS::ANIMPOSTFX_STOP("DeathFailMP01");
// 			if (!failFX) GRAPHICS::ANIMPOSTFX_STOP("MissionFail01");
// 		}
// 		// END IMMERSION FX +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// 		if (!headshotImmunity) PED::SET_PED_CONFIG_FLAG(playerPed, 263, false); // disable playerPed headshot immunity
//
// 		// START HOSTILE BLIP +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		if (!hostileBlip)
// 		{
// 			Ped hostilePed[1024];
// 			int hostileRange = 1024;
// 			int count = worldGetAllPeds(hostilePed, hostileRange);
//
// 			for (int i = 0; i < count; i++)
// 			{
// 				if (hostileBlipMap.find(hostilePed[i]) == hostileBlipMap.end()) hostileBlipMap[hostilePed[i]] = 0; // initialize map
// 			}
//
// 			for (int i = 0; i < count; i++)
// 			{
// 				if (!hostileBlipOnMission)
// 				{
// 					if (PLR.IsPedHostileAndNearby(hostilePed[i]) || PLR.IsInCombat() || PLR.IsPursued() || PLR.IsInMission()) // returns TRUE whenever hostile is nearby/player in combat, being pursued/wanted or in mission (hopefully works for stealth missions)
// 					{
// 						if (hostilePed[i] != playerPed && hostilePed[i] != horsePed && !World::IsPedFriendly(hostilePed[i]) && ENTITY::IS_ENTITY_A_PED(hostilePed[i]) && !PED::IS_PED_DEAD_OR_DYING(hostilePed[i], true)) // not playerPed, horsePed, friendlyPed, a ped & not dead
// 						{
// 							PED::REQUEST_PED_VISIBILITY_TRACKING(ENTITY::GET_PED_INDEX_FROM_ENTITY_INDEX(hostilePed[i])); // track these hostile peds if all is true
// 							hostileBlipMap[hostilePed[i]] = MAP::GET_BLIP_FROM_ENTITY(hostilePed[i]); // save em in a Ped <-> Blip Map
//
// 							if (PED::IS_TRACKED_PED_VISIBLE(ENTITY::GET_PED_INDEX_FROM_ENTITY_INDEX(hostilePed[i]))) // within player fov
// 							{
// 								MAP::_BLIP_SET_MODIFIER(hostileBlipMap[hostilePed[i]], Keys::GetHash("BLIP_MODIFIER_FADE_IN"));
// 								MAP::_BLIP_SET_STYLE(hostileBlipMap[hostilePed[i]], Keys::GetHash("BLIP_MODIFIER_FADE"));
// 							}
// 							else if (!PED::IS_TRACKED_PED_VISIBLE(ENTITY::GET_PED_INDEX_FROM_ENTITY_INDEX(hostilePed[i]))) // not within player fov
// 							{
// 								MAP::_BLIP_SET_MODIFIER(hostileBlipMap[hostilePed[i]], Keys::GetHash("BLIP_MODIFIER_FADE"));
// 								MAP::_BLIP_SET_STYLE(hostileBlipMap[hostilePed[i]], Keys::GetHash("BLIP_MODIFIER_FADE_OUT_SLOW"));
// 							}
// 						}
// 					}
// 				}
// 				else if (hostileBlipOnMission)
// 				{
// 					if (PLR.IsPedHostileAndNearby(hostilePed[i]) || PLR.IsInCombat() || (PLR.IsPursued() && !PLR.IsInMission())) // returns TRUE whenever hostile is nearby/player in combat, being pursued/wanted and not in mission (hopefully works for stealth missions)
// 					{
// 						if (hostilePed[i] != playerPed && hostilePed[i] != horsePed && !World::IsPedFriendly(hostilePed[i]) && ENTITY::IS_ENTITY_A_PED(hostilePed[i]) && !PED::IS_PED_DEAD_OR_DYING(hostilePed[i], true)) // not playerPed, horsePed, friendlyPed, a ped & not dead
// 						{
// 							PED::REQUEST_PED_VISIBILITY_TRACKING(ENTITY::GET_PED_INDEX_FROM_ENTITY_INDEX(hostilePed[i])); // track these hostile peds if all is true
// 							hostileBlipMap[hostilePed[i]] = MAP::GET_BLIP_FROM_ENTITY(hostilePed[i]); // save em in a Ped <-> Blip Map
//
// 							if (PED::IS_TRACKED_PED_VISIBLE(ENTITY::GET_PED_INDEX_FROM_ENTITY_INDEX(hostilePed[i]))) // within player fov
// 							{
// 								MAP::_BLIP_SET_MODIFIER(hostileBlipMap[hostilePed[i]], Keys::GetHash("BLIP_MODIFIER_FADE"));
// 								MAP::_BLIP_SET_MODIFIER(hostileBlipMap[hostilePed[i]], Keys::GetHash("BLIP_MODIFIER_FADE_IN"));
// 							}
// 							else if (!PED::IS_TRACKED_PED_VISIBLE(ENTITY::GET_PED_INDEX_FROM_ENTITY_INDEX(hostilePed[i]))) // not within player fov
// 							{
// 								MAP::_BLIP_SET_MODIFIER(hostileBlipMap[hostilePed[i]], Keys::GetHash("BLIP_MODIFIER_FADE"));
// 								MAP::_BLIP_SET_MODIFIER(hostileBlipMap[hostilePed[i]], Keys::GetHash("BLIP_MODIFIER_FADE_OUT_SLOW"));
// 							}
// 						}
// 					}
// 				}
// 			}
// 		}
// 		// END HOSTILE BLIP +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// 		// START OF SLEEP STAMINA ONLY PART +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		if (sleepStaminaOnly)
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
// 		// END OF BATH DEADEYE ONLY PART ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// 		// START DISABLE GLOW PART ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		if (!pickupsGlow)
// 		{
// 			Pickup pickups[512];
// 			int pickupsRange = 512;
// 			int pCount = worldGetAllPickups(pickups, pickupsRange); // disabling weapon pickups glow
// 			for (int i = 0; i < pCount; i++) GRAPHICS::_0x50C14328119E1DD1(pickups[i], true); // yep this native below directly disables the glow
// 		}
//
// 		if (!objectsGlow)
// 		{
// 			Object objects[512];
// 			int objectsRange = 512;
// 			int oCount = worldGetAllObjects(objects, objectsRange); // disabling lootable object such as apple, carrot and such
// 			for (int i = 0; i < oCount; i++) GRAPHICS::_0x50C14328119E1DD1(objects[i], true);
// 		}
// 		// END DISABLE GLOW PART ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// 		// START OF DEADEYE NO RELOAD PART ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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
// 		// END OF IMMERSION PART ================================================================================================================
//
// 		// CORE PART ============================================================================================================================
// 		if (PLR.IsPlaying() && !isPlaying)
// 		{
// 			isPlaying = true;
// 			LOGGER.Write("hooked player is playing");
// 		}
// 		else if (!PLR.IsPlaying() && isPlaying)
// 		{
// 			isPlaying = false;
// 			LOGGER.Write("hooked player is not playing");
// 		}
//
// 		static bool isStoryPostFX = false;
//
// 		if (World::IsStoryFXPlaying() && !isStoryPostFX)
// 		{
// 			isStoryPostFX = true;
// 			LOGGER.Write("hooked isStoryPostFX running");
// 		}
// 		else if (!World::IsStoryFXPlaying() && isStoryPostFX)
// 		{
// 			isStoryPostFX = false;
// 			LOGGER.Write("hooked isStoryPostFX stopped");
// 		}
//
// 		if ((isPlaying && !isStoryPostFX) || (ENTITY::DOES_ENTITY_EXIST(horsePed) && !ENTITY::IS_ENTITY_DEAD(horsePed))) // do this first else will crash on new game, also disable the core part of the mod while in storyPostFX
// 		{
// 			float playerHealthRegen = static_cast<float>(GetPrivateProfileInt("CORE_MODIFIER", "PLAYER_HEALTH_REGEN", 50, ".\\SoftCores.ini")) / 100.0f;
// 			int playerHpPercentageDrain = GetPrivateProfileInt("CORE_MODIFIER", "PLAYER_HEALTH_PENALTY", 4, ".\\SoftCores.ini") * ENTITY::GET_ENTITY_MAX_HEALTH(playerPed, 0) / 100;
// 			int horseHpPercentageDrain = GetPrivateProfileInt("CORE_MODIFIER", "HORSE_HEALTH_PENALTY", 4, ".\\SoftCores.ini") * ENTITY::GET_ENTITY_MAX_HEALTH(horsePed, 0) / 100;
//
// 			// START TEMPERATURE CORE +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 			float pointsDifferences;
// 			int outfitModifier;
//
// 			if (temperatureCore) // this on to be called every tick
// 			{
// 				float pointsModifier = 0.0f; // default no points modifier, just uses surrounding temperature as base value to determine clothes points needed
//
// 				// isNearFireModifier ***********************************************************************************************************
//
// 				bool isNearFireModifier;
// 				isNearFireModifier = false;
//
// 				Vector3 nearestFire = Vector3();
// 				Vector3 playerPos = ENTITY::GET_ENTITY_COORDS(playerPed, true, true);
//
// 				float fireModifier = static_cast<float>(GetPrivateProfileInt("TEMPERATURE_MODIFIER", "FIRE_MODIFIER", 50, ".\\SoftCores.ini")) / 100.0f;
//
// 				if (FIRE::GET_CLOSEST_FIRE_POS(&nearestFire, playerPos.x, playerPos.y, playerPos.z))
// 				{
// 					if (MISC::GET_DISTANCE_BETWEEN_COORDS(playerPos.x, playerPos.y, playerPos.z, nearestFire.x, nearestFire.y, nearestFire.z, true) < 4.0f && !isNearFireModifier)
// 					{
// 						isNearFireModifier = true;
// 						stringstream text;
// 						text << "hooked player near fire, fireModifer: " << fireModifier << " positive points (hotness)";
// 						LOGGER.Write(text.str().c_str());
// 					}
// 					else if (MISC::GET_DISTANCE_BETWEEN_COORDS(playerPos.x, playerPos.y, playerPos.z, nearestFire.x, nearestFire.y, nearestFire.z, true) > 4.0f && isNearFireModifier)
// 					{
// 						isNearFireModifier = false;
// 						LOGGER.Write("hooked player far from fire");
// 					}
// 				}
//
// 				if (isNearFireModifier) pointsModifier = pointsModifier + fireModifier; // positive point value for hotness
//
// 				// isCampfireModifier ***********************************************************************************************************
//
// 				bool isCampfireModifier;
// 				isCampfireModifier = false;
//
// 				float campFireModifier = (float)GetPrivateProfileInt("TEMPERATURE_MODIFIER", "CAMPFIRE_MODIFIER", 50, ".\\SoftCores.ini") / 100.0f;
//
// 				if (PLR.IsInControl() && PLR.IsInCampScenario() && !isCampfireModifier)
// 				{
// 					isCampfireModifier = true;
// 					stringstream text;
// 					text << "hooked player started campfire scenario, campFireModifier: " << campFireModifier << " positive points (hotness)";
// 					LOGGER.Write(text.str().c_str());
// 				}
// 				else if (PLR.IsInControl() && PLR.IsMoving() && !PLR.IsInCampScenario() && isCampfireModifier)
// 				{
// 					isCampfireModifier = false;
// 					LOGGER.Write("hooked player stopped campfire scenario");
// 				}
//
// 				if (isCampfireModifier) pointsModifier = pointsModifier + campFireModifier; // positive point value for hotness
//
// 				// isNotOutsideModifier ***********************************************************************************************************
//
// 				bool isIndoorModifier;
// 				isIndoorModifier = false;
//
// 				float indoorModifier = (float)GetPrivateProfileInt("TEMPERATURE_MODIFIER", "INDOOR_MODIFIER", 100, ".\\SoftCores.ini") / 100.0f;
//
// 				if (PLR.IsIndoors() && !isIndoorModifier)
// 				{
// 					isIndoorModifier = true;
//
// 					stringstream text;
// 					text << "hooked player is indoor, indoorModifier: " << indoorModifier << " positive points (hotness)";
// 					LOGGER.Write(text.str().c_str());
// 				}
// 				else if (!PLR.IsIndoors() && isIndoorModifier)
// 				{
// 					isIndoorModifier = false;
// 					LOGGER.Write("hooked player is outdoor");
// 				}
//
// 				if (isIndoorModifier) pointsModifier = pointsModifier + indoorModifier; // positive point value for hotness
//
// 				// isSubmergedModifier ***********************************************************************************************************
//
// 				bool isSubmergedModifier;
// 				isSubmergedModifier = false;
//
// 				float submergedModifier = (float)GetPrivateProfileInt("TEMPERATURE_MODIFIER", "SUBMERGED_MODIFIER", 100, ".\\SoftCores.ini") / 100.0f;
//
// 				if (PLR.IsSubmerged() && !isSubmergedModifier)
// 				{
// 					isSubmergedModifier = true;
// 					submergedModifier = submergedModifier + ENTITY::GET_ENTITY_SUBMERGED_LEVEL(playerPed);
// 					stringstream text;
// 					text << "hooked player is submerged, submergedModifier: " << submergedModifier << " negative points (coldness)";
// 					LOGGER.Write(text.str().c_str());
// 				}
// 				else if (!PLR.IsSubmerged() && isSubmergedModifier)
// 				{
// 					isSubmergedModifier = false;
// 					LOGGER.Write("hooked player is no longer submerged");
// 				}
//
// 				if (isSubmergedModifier) pointsModifier = pointsModifier - submergedModifier; // negative point value for coldness
//
// 				if (!isIndoorModifier) // only apply raining & snowing modifier when player is not indoor
// 				{
// 					// isRainingModifier ***********************************************************************************************************
//
// 					bool isRainingModifier;
// 					isRainingModifier = false;
//
// 					float rainingModifier = (float)GetPrivateProfileInt("TEMPERATURE_MODIFIER", "RAINING_MODIFIER", 50, ".\\SoftCores.ini") / 100.0f;
//
// 					if (World::IsRaining() && !isRainingModifier)
// 					{
// 						isRainingModifier = true;
// 						rainingModifier = rainingModifier + MISC::GET_RAIN_LEVEL();
// 						stringstream text;
// 						text << "hooked is raining, rainingModifier: " << rainingModifier << " negative points (coldness)";
// 						LOGGER.Write(text.str().c_str());
// 					}
// 					else if (!World::IsRaining() && isRainingModifier)
// 					{
// 						isRainingModifier = false;
// 						LOGGER.Write("hooked is no longer raining");
// 					}
//
// 					if (isRainingModifier) pointsModifier = pointsModifier - rainingModifier; // negative point value for coldness
//
// 					// isSnowingModifier ***********************************************************************************************************
//
// 					bool isSnowingModifier;
// 					isSnowingModifier = false;
//
// 					float snowingModifier = (float)GetPrivateProfileInt("TEMPERATURE_MODIFIER", "SNOWING_MODIFIER", 100, ".\\SoftCores.ini") / 100.0f;
//
// 					if (World::IsSnowing() && !isSnowingModifier)
// 					{
// 						isSnowingModifier = true;
// 						snowingModifier = snowingModifier + MISC::GET_SNOW_LEVEL();
// 						stringstream text;
// 						text << "hooked is snowing, snowingModifier: " << snowingModifier << " negative points (coldness)";
// 						LOGGER.Write(text.str().c_str());
// 					}
// 					else if (!World::IsSnowing() && isSnowingModifier)
// 					{
// 						isSnowingModifier = false;
// 						LOGGER.Write("hooked is no longer snowing");
// 					}
//
// 					if (isSnowingModifier) pointsModifier = pointsModifier - snowingModifier;  // negative point value for coldness
// 				}
//
// 				pointsDifferences = PLR.GetClothingTemperaturePoints() - Temp::GetClothingTemperaturePointsRequired() + pointsModifier; // stack with pointsModifer which accumulates +ve points for hotness and -ve points for coldness
//
// 				const char* spriteModifier;
//
// 				float coldThreshold = -1.0f * (float)GetPrivateProfileInt("TEMPERATURE_MODIFIER", "COLD_THRESHOLD", 150, ".\\SoftCores.ini") / 100.0f; // this is negative points
// 				float hotThreshold = (float)GetPrivateProfileInt("TEMPERATURE_MODIFIER", "HOT_THRESHOLD", 400, ".\\SoftCores.ini") / 100.0f;
//
// 				outfitModifier = 1;
// 				if (pointsDifferences < coldThreshold) // simulate cold if pointDifferences is less than -1.5, say player is wearing 6.0 points of clothing vs 8.0 points of temperature, outfitModifier is cold
// 				{
// 					outfitModifier = 0;
// 					spriteModifier = "RPG_COLD";
// 				}
// 				else if (pointsDifferences >= coldThreshold && pointsDifferences < hotThreshold) // simulate warm, ideal condition
// 				{
// 					outfitModifier = 1;
// 					spriteModifier = "RPG_WARM";
// 				}
// 				else if (pointsDifferences >= hotThreshold) // simulate hot if pointDifferences is more or equal than 4.0, say player is wearing 10.0 points of clothing vs 6.0 points of temperature, outfitModifier is hot
// 				{
// 					outfitModifier = 2;
// 					spriteModifier = "RPG_HOT";
// 				}
//
// 				bool isBathing;
//
// 				isBathing = false;
// 				if (PLR.IsBathing()) isBathing = true; // this can only be entered during inital bathing moment
// 				else if (!PLR.IsBathing()) isBathing = (PLR.IsMoving()) ? false : true; // set to false when player starts moving
//
// 				if (temperatureCoreSprite) // only show sprite when true on ini configuration file
// 				{
// 					bool drawSprite;
//
// 					drawSprite = false;
// 					if (PAD::IS_CONTROL_JUST_PRESSED(0, Keys::GetHash("INPUT_REVEAL_HUD")) && !PAD::IS_CONTROL_PRESSED(0, Keys::GetHash("INPUT_OPEN_WHEEL_MENU")) && !HUD::IS_HUD_HIDDEN() && !PLR.IsActiveInScenario() && !isBathing)
// 					{
// 						drawSprite = true;
//
// 						stringstream text;
// 						text << "hooked player is showing sprite, spriteModifier: " << spriteModifier << " overall clothing points: " << PLR.GetClothingTemperaturePoints() << " needs: " << Temp::GetClothingTemperaturePointsRequired() + pointsModifier;
// 						LOGGER.Write(text.str().c_str());
// 					}
//
// 					if (drawSprite)
// 					{
// 						if (!TXD::_HAS_STREAMED_TXD_LOADED(Keys::GetHash("RPG_TEXTURES")))
// 						{
// 							TXD::REQUEST_STREAMED_TEXTURE_DICT("RPG_TEXTURES", false);
// 						}
// 						else if (TXD::_HAS_STREAMED_TXD_LOADED(Keys::GetHash("RPG_TEXTURES")) && strcmp(spriteModifier, "RPG_WARM") != 0)
// 						{
// 							GRAPHICS::DRAW_SPRITE("RPG_TEXTURES", spriteModifier, 0.25f, 0.9f, 0.045f, 0.07f, 0.0f, 240, 240, 240, 180, false);
// 						}
// 					}
// 				}
//
// 				// Hat & Gloves prompts ***********************************************************************************************************
// 				// Show prompts for removal when away from horse and got 'em currently equipped
//
// 				if (PAD::IS_CONTROL_PRESSED(0, Keys::GetHash("INPUT_SELECT_RADAR_MODE")) && PLR.IsWearing(ClothingType::Hats) && !PLR.IsActiveInScenario() && !isBathing)
// 				{
// 					UI::TogglePrompt(hatPrompt, true, true);
// 				}
// 				else
// 				{
// 					UI::TogglePrompt(hatPrompt, false, false);
// 				}
//
// 				if (HUD::_UIPROMPT_HAS_STANDARD_MODE_COMPLETED(hatPrompt, 0))
// 				{
// 					PLR.UnequipClothes(ClothingType::Hats);
// 					LOGGER.Write("hooked player unequips hat");
// 					UI::TogglePrompt(hatPrompt, false, false);
// 				}
//
// 				if (PAD::IS_CONTROL_PRESSED(0, Keys::GetHash("INPUT_SELECT_RADAR_MODE")) && PLR.IsWearing(ClothingType::Gloves) && !PLR.IsActiveInScenario() && !isBathing)
// 				{
// 					UI::TogglePrompt(glovePrompt, true, true);
// 				}
// 				else
// 				{
// 					UI::TogglePrompt(glovePrompt, false, false);
// 				}
//
// 				if (HUD::_UIPROMPT_HAS_STANDARD_MODE_COMPLETED(glovePrompt, 0))
// 				{
// 					PLR.UnequipClothes(ClothingType::Gloves);
// 					LOGGER.Write("hooked player unequips gloves");
// 					UI::TogglePrompt(glovePrompt, false, false);
// 				}
//
// 				(outfitModifier == 2) ? PED::SET_PED_RESET_FLAG(playerPed, 139, true) : PED::SET_PED_RESET_FLAG(playerPed, 139, false); // if outfit is hot, no stamina regen
//
// 				bool knockedOut;
//
// 				knockedOut = false;
// 				temperatureMs = (outfitModifier == 2 || knockedOut) ? (GetPrivateProfileInt("TIMERS", "TEMPERATURE_PENALTY", 8000, ".\\SoftCores.ini") * 2) : GetPrivateProfileInt("TIMERS", "TEMPERATURE_PENALTY", 8000, ".\\SoftCores.ini"); // if outfit is hot/knockedOut previously, temperatureMs is doubled
//
// 				if (PLR.IsInControl() && !isBathing) // returns TRUE if player is in control && not bathing
// 				{
// 					if (World::GetGameTimer() > temperatureTimer) // penalty timer for player outfit in accordance to surrounding temperature, called every temperatureTimer
// 					{
// 						stringstream text;
// 						int temperatureHpPercentageDrain = Math::Ceil(fabsf(pointsDifferences)) * ENTITY::GET_ENTITY_MAX_HEALTH(playerPed, 0) / 100; // calculater hp drain, convert the pointsDifferences to positive first
//
// 						switch (outfitModifier)
// 						{
// 						case 0: // cold
// 							if(temperatureCoreFx) GRAPHICS::ANIMPOSTFX_PLAY("PlayerHonorLevelBad"); // grayish tint, seems suitable enough to show player is cold
// 							(ENTITY::GET_ENTITY_HEALTH(playerPed) - temperatureHpPercentageDrain <= 1) ? ENTITY::_SET_ENTITY_HEALTH(playerPed, 1, 1) : ENTITY::_SET_ENTITY_HEALTH(playerPed, (ENTITY::GET_ENTITY_HEALTH(playerPed) - temperatureHpPercentageDrain), 0); // hp outer core drain
// 							if (PLR.GetCore(Core::Health) < 10 && Math::HealthAsPercentage(playerPed) < 10 && !PLR.IsCoreOverpowered(Core::Health) && !PLR.IsOuterCoreOverpowered(Core::Health) && !knockedOut) // when reached this threshold, knock player out
// 							{
// 								TASK::TASK_KNOCKED_OUT(playerPed, 0.0f, false);
// 								knockedOut = true;
// 								text << "hooked cold effect with health less that 10%, knockedOut, next occurence after " << temperatureMs * 2 << " ms";
// 								LOGGER.Write(text.str().c_str());
// 							}
// 							else
// 							{
// 								text << "hooked cold effect, next occurence after " << temperatureMs << " ms";
// 								LOGGER.Write(text.str().c_str());
// 								knockedOut = false;
// 							}
// 							break;
// 						case 1: // warm
// 							break;
// 						case 2: // hot
// 							if (temperatureCoreFx) GRAPHICS::ANIMPOSTFX_PLAY("PlayerHonorLevelGood"); // reddish tint, seems suitable enough to show player is hot
// 							text << "hooked hot effect, next occurence after " << temperatureMs * 2 << " ms";
// 							LOGGER.Write(text.str().c_str());
// 							break;
// 						default:
// 							break;
// 						}
//
// 						temperatureMs = (outfitModifier == 2 || knockedOut) ? (GetPrivateProfileInt("TIMERS", "TEMPERATURE_PENALTY", 8000, ".\\SoftCores.ini") * 2) : GetPrivateProfileInt("TIMERS", "TEMPERATURE_PENALTY", 8000, ".\\SoftCores.ini"); // if outfit is hot/knockedOut previously, temperatureMs is doubled
// 						temperatureTimer = World::GetGameTimer() + temperatureMs; // if knocked out previously, the next timer will be longer to allow recovery period
// 					}
// 				}
// 			}
// 			// END TEMPERATURE CORE +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// 			// START AIMING PENALTY +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 			if (aimPenalty)
// 			{
// 				int stAimingPenalty = GetPrivateProfileInt("CORE_MODIFIER", "STAMINA_AIMING_PENALTY", 4, ".\\SoftCores.ini") * PLR.GetMaxOuterCore(Core::Stamina) / 100;
// 				int deAimingPenalty = GetPrivateProfileInt("CORE_MODIFIER", "DEADEYE_AIMING_PENALTY", 8, ".\\SoftCores.ini") * PLR.GetMaxOuterCore(Core::DeadEye) / 100;
// 				bool isAimingAir = false;
//
// 				if (PAD::IS_CONTROL_JUST_PRESSED(0, Keys::GetHash("INPUT_AIM_IN_AIR")) || PAD::IS_CONTROL_PRESSED(0, Keys::GetHash("INPUT_AIM_IN_AIR"))) isAimingAir = !isAimingAir;
//
// 				if (World::GetGameTimer() > aimTimer)
// 				{
// 					stAimingPenalty = (PLR.IsOuterCoreOverpowered(Core::Stamina)) ? 0 : stAimingPenalty;
// 					deAimingPenalty = (PLR.IsOuterCoreOverpowered(Core::DeadEye)) ? 0 : deAimingPenalty;
//
// 					if (PLAYER::IS_PLAYER_FREE_AIMING(playerID) && !isAimingAir)
// 					{
// 						Hash aimedWeapon;
// 						if (WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &aimedWeapon, false, 0, true))
// 						{
// 							if (!Weapons::IsItem(aimedWeapon) && !Weapons::IsThrowableOnly(aimedWeapon) && !Weapons::IsMelee(aimedWeapon)) // if not unique and not throwable
// 							{
// 								PED::SET_PED_RESET_FLAG(playerPed, 139, true); // disable stamina outer core regen
//
// 								if (!PLR.IsOuterCoreOverpowered(Core::Stamina)) // only occurs if not overpowered by potions, let game handles that instead
// 								{
// 									(PLR.GetOuterCore(Core::Stamina) - stAimingPenalty <= 0) ? PLR.SetOuterCore(Core::Stamina, 0) : PLR.SetOuterCore(Core::Stamina, PLR.GetOuterCore(Core::Stamina) - stAimingPenalty); // drain outer stamina core until empty
// 								}
//
// 								if (!PLR.IsOuterCoreOverpowered(Core::DeadEye)) // only occurs if not overpowered by potions, let game handles that instead
// 								{
// 									(PLR.GetOuterCore(Core::DeadEye) - deAimingPenalty <= 0) ? PLR.SetOuterCore(Core::DeadEye, 0) : PLR.SetOuterCore(Core::DeadEye, PLR.GetOuterCore(Core::DeadEye) - deAimingPenalty); // drain outer deadeye core until empty
// 								}
//
// 								if (PLR.GetOuterCore(Core::Stamina) == 0) // if stamina outer core is empty
// 								{
// 									if (!PLR.IsCoreOverpowered(Core::Stamina)) // and main core is not overpowered
// 									{
// 										(PLR.GetCore(Core::Stamina) - 1 <= 0) ? PLR.SetCore(Core::Stamina, 0) : PLR.SetCore(Core::Stamina, PLR.GetCore(Core::Stamina) - 1); // drains main stamina core
// 									}
// 								}
//
// 								if (PLR.GetOuterCore(Core::DeadEye) == 0) // if stamina outer core is empty
// 								{
// 									if (!PLR.IsCoreOverpowered(Core::DeadEye)) // and main core is not overpowered
// 									{
// 										(PLR.GetCore(Core::DeadEye) - 1 <= 0) ? PLR.SetCore(Core::DeadEye, 0) : PLR.SetCore(Core::DeadEye, PLR.GetCore(Core::DeadEye) - 1); // drains main deadeye core
// 									}
// 								}
// 							}
// 						}
// 					}
// 					else if (!PLAYER::IS_PLAYER_FREE_AIMING(playerID) || isAimingAir)
// 					{
// 						(PLR.GetOuterCore(Core::Stamina) + stAimingPenalty < PLR.GetMaxOuterCore(Core::Stamina)) ? PLR.SetOuterCore(Core::Stamina, PLR.GetOuterCore(Core::Stamina) + stAimingPenalty) : PLR.SetOuterCore(Core::Stamina, PLR.GetMaxOuterCore(Core::Stamina)); // restore outer core stamina until max
// 						(PLR.GetOuterCore(Core::DeadEye) + deAimingPenalty < PLR.GetMaxOuterCore(Core::DeadEye)) ? PLR.SetOuterCore(Core::DeadEye, PLR.GetOuterCore(Core::DeadEye) + deAimingPenalty) : PLR.SetOuterCore(Core::DeadEye, PLR.GetMaxOuterCore(Core::DeadEye)); // restore outer core  deadeye until max
//
// 						PED::SET_PED_RESET_FLAG(playerPed, 139, false); // enable stamina outer core regen
// 					}
//
// 					aimTimer = World::GetGameTimer() + aimMs;
// 				}
// 			}
// 			// END AIMING PENALTY +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// 			// START CORE DRAIN +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 			if (World::GetGameTimer() > depletionTimer) // every time game timer has pass the timeMs mark, set main core drain values accordingly, called every depletionTimer
// 			{
// 				// dynamic drain values according to time of day
// 				float drainModifier = Temp::GetTimeOfDayModifier();
//
// 				if (!PLR.IsIdle() && PLR.IsInControl() && (!PLR.IsActiveInScenario() || !PLR.IsUsingAnyScenario())) // returns TRUE if player is not idle and in control and not active in scenario or using any
// 				{
// 					// PLAYER Cores
// 					int playerHpDrain = (PLR.IsCoreOverpowered(Core::Health)) ? 0 : Math::Ceil(drainModifier * playerHpModifier);
// 					int playerStDrain = (PLR.IsCoreOverpowered(Core::Stamina)) ? 0 : Math::Ceil(drainModifier * playerStModifier);
// 					int playerDeDrain = (PLR.IsCoreOverpowered(Core::DeadEye)) ? 0 : Math::Ceil(drainModifier * playerDeModifier);
//
// 					// HORSE Cores
// 					int horseHpDrain = (PLR.IsHorseCoreOverpowered(Core::Health)) ? 0 : Math::Ceil(drainModifier * horseHpModifier);
// 					int horseStDrain = (PLR.IsHorseCoreOverpowered(Core::Stamina)) ? 0 : Math::Ceil(drainModifier * horseStModifier);
//
// 					// if player on mount, all core drain slower by calculated above else, horse core drain slower
// 					if (PLR.IsMounted())
// 					{
// 						playerHpDrain = Math::Floor(playerHpDrain * 0.5f);
// 						playerStDrain = Math::Floor(playerStDrain * 0.5f);
// 						playerDeDrain = Math::Floor(playerDeDrain * 0.5f);
// 					}
// 					else
// 					{
// 						horseHpDrain = Math::Floor(horseHpDrain * 0.5f);
// 						horseStDrain = Math::Floor(horseStDrain * 0.5f);
// 					}
//
// 					if (temperatureCore) // if temperatureCore feature enabled in .ini configuration, apply temperature modifier to base main core drain effects
// 					{
// 						float temperatureModifier;
// 						stringstream text;
//
// 						switch (outfitModifier)
// 						{
// 						case 0: // cold
// 							playerHealthRegen = 0.0f; // no hp regen at all
// 							temperatureModifier = 1.0f + fabsf(pointsDifferences);
// 							playerHpDrain = Math::Ceil(playerHpDrain * temperatureModifier);
// 							depletionMs = GetPrivateProfileInt("TIMERS", "CORE_DEPLETION", 120000, ".\\SoftCores.ini") / 2; // if outfit is not warm, core depletionMs is faster by 50%
// 							text << "hooked cold effect, next core drain occurence after " << depletionMs << " ms playerHpDrain: " << playerHpDrain << " playerStDrain: " << playerStDrain << " playerDeDrain: " << playerDeDrain;
// 							LOGGER.Write(text.str().c_str());
// 							break;
// 						case 1: // warm, all core drain slower by 10 %
// 							playerHealthRegen = (PLR.IsCoreOverpowered(Core::Health)) ? 1.0f : playerHealthRegen;
// 							temperatureModifier = 0.9f;
// 							playerHpDrain = Math::Floor(playerHpDrain * temperatureModifier);
// 							playerStDrain = Math::Floor(playerStDrain * temperatureModifier);
// 							playerDeDrain = Math::Floor(playerDeDrain * temperatureModifier);
// 							depletionMs = GetPrivateProfileInt("TIMERS", "CORE_DEPLETION", 120000, ".\\SoftCores.ini"); // if outfit warm, core depletionMs is as set in .ini configuration file
// 							text << "hooked warm effect, next core drain occurence after " << depletionMs << " ms playerHpDrain: " << playerHpDrain << " playerStDrain: " << playerStDrain << " playerDeDrain: " << playerDeDrain;
// 							LOGGER.Write(text.str().c_str());
// 							break;
// 						case 2: // hot
// 							playerHealthRegen = playerHealthRegen * 0.2f; // slowed health outer core regen by 80%
// 							temperatureModifier = 0.5f + pointsDifferences;
// 							playerStDrain = Math::Ceil(playerStDrain * temperatureModifier);
// 							playerDeDrain = Math::Ceil(playerDeDrain * temperatureModifier);
// 							depletionMs = GetPrivateProfileInt("TIMERS", "CORE_DEPLETION", 120000, ".\\SoftCores.ini") / 2; // if outfit is not warm, core depletionMs is faster by 50%
// 							text << "hooked hot effect, next core drain occurence after " << depletionMs << " ms playerHpDrain: " << playerHpDrain << " playerStDrain: " << playerStDrain << " playerDeDrain: " << playerDeDrain;
// 							LOGGER.Write(text.str().c_str());
// 							break;
// 						default:
// 							break;
// 						}
// 					}
// 					else if (!temperatureCore)
// 					{
// 						stringstream text;
// 						text << "hooked core drain effect, next core drain occurence after " << depletionMs << " ms playerHpDrain: " << playerHpDrain << " playerStDrain: " << playerStDrain << " playerDeDrain: " << playerDeDrain;
// 						LOGGER.Write(text.str().c_str());
// 						playerHealthRegen = (PLR.IsCoreOverpowered(Core::Health)) ? 1.0f : playerHealthRegen;
// 					}
//
// 					// calculate both PLAYER and HORSE core drain accordingly
// 					(PLR.GetCore(Core::Health) - playerHpDrain <= 0) ? PLR.SetCore(Core::Health, 0) : PLR.SetCore(Core::Health, PLR.GetCore(Core::Health) - playerHpDrain);
// 					(PLR.GetCore(Core::Stamina) - playerStDrain <= 0) ? PLR.SetCore(Core::Stamina, 0) : PLR.SetCore(Core::Stamina, PLR.GetCore(Core::Stamina) - playerStDrain);
// 					(PLR.GetCore(Core::DeadEye) - playerDeDrain <= 0) ? PLR.SetCore(Core::DeadEye, 0) : PLR.SetCore(Core::DeadEye, PLR.GetCore(Core::DeadEye) - playerDeDrain);
//
// 					(PLR.GetHorseCore(Core::Health) - horseHpDrain <= 0) ? PLR.SetHorseCore(Core::Health, 0) : PLR.SetHorseCore(Core::Health, PLR.GetHorseCore(Core::Health) - horseHpDrain);
// 					(PLR.GetHorseCore(Core::Stamina) - horseStDrain <= 0) ? PLR.SetHorseCore(Core::Stamina, 0) : PLR.SetHorseCore(Core::Stamina, PLR.GetHorseCore(Core::Stamina) - horseStDrain);
// 				}
//
// 				depletionTimer = World::GetGameTimer() + depletionMs;
// 			}
//
// 			if (World::GetGameTimer() > healthTimer) // every time game timer has pass the healthMs mark, set outer core drain values accordingly, called every healthTimer
// 			{
// 				if (!PLR.IsIdle() && PLR.IsInControl() && (!PLR.IsActiveInScenario() || !PLR.IsUsingAnyScenario())) // returns TRUE if player is not idle and in control and not active in scenario or using any
// 				{
// 					if (PLR.GetCore(Core::Health) <= 0 && !PLR.IsCoreOverpowered(Core::Health))
// 					{
// 						playerHealthRegen = 0.0f;
// 						(ENTITY::GET_ENTITY_HEALTH(playerPed) - playerHpPercentageDrain <= 1) ? ENTITY::_SET_ENTITY_HEALTH(playerPed, 1, 1) : ENTITY::_SET_ENTITY_HEALTH(playerPed, (ENTITY::GET_ENTITY_HEALTH(playerPed) - playerHpPercentageDrain), 0); // health outer core penalty for main core being empty
// 					}
//
// 					if (PLR.IsMounted() && PLR.GetHorseCore(Core::Health) <= 0 && !PLR.IsHorseCoreOverpowered(Core::Health)) // only if player is on mount
// 					{
// 						(ENTITY::GET_ENTITY_HEALTH(horsePed) - horseHpPercentageDrain <= 1) ? ENTITY::_SET_ENTITY_HEALTH(horsePed, 1, 1) : ENTITY::_SET_ENTITY_HEALTH(horsePed, (ENTITY::GET_ENTITY_HEALTH(horsePed) - horseHpPercentageDrain), 0);
// 					}
// 				}
// 				healthTimer = World::GetGameTimer() + healthMs;
// 			}
//
// 			(PLR.GetCore(Core::Stamina) <= 0) ? PED::SET_PED_RESET_FLAG(playerPed, 139, true) : PED::SET_PED_RESET_FLAG(playerPed, 139, false); // if main stamina core is empty, no stamina regen
//
// 			(PLR.IsCoreOverpowered(Core::DeadEye) || PLR.IsOuterCoreOverpowered(Core::DeadEye)) ? PED::SET_PED_ACCURACY(playerPed, 100) : PED::SET_PED_ACCURACY(playerPed, PLR.GetCore(Core::DeadEye)); // if deadeye main or outer core is overpowered, accuracy is 100%, else, ties to deadeye main core value
//
// 			(PLR.IsInCombat() && (!PLR.IsMounted() || !PLR.IsInCover())) ? PLR.SetHealthRegen(0.0f) : PLR.SetHealthRegen(playerHealthRegen); // no regen in combat unless on mount or in cover
// 			// END CORE DRAIN +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// 			// START OF DEATH PENALTY +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 			if (PLR.IsInMission() && !isInMission)
// 			{
// 				LOGGER.Write("hooked player is in mission, penalty on death disabled");
// 				isInMission = true;
// 			}
// 			else if (!PLR.IsInMission() && isInMission)
// 			{
// 				isInMission = false;
// 				LOGGER.Write("hooked player is not in mission, penalty on death enabled");
// 			}
//
// 			if (penaltyOnDeath && !isInMission)
// 			{
// 				bool coresPenalty;
// 				bool deathPenalty;
// 				int deathTime;
//
// 				deathPenalty = false;
// 				coresPenalty = false;
// 				if (!PLR.IsMoving() && !PLR.IsAlive() && !PLR.IsPlaying() && !coresPenalty)
// 				{
// 					deathTime = PED::GET_PED_TIME_OF_DEATH(playerPed);
// 					coresPenalty = true;
// 					LOGGER.Write("hooked player is not moving, just died, not playing and !coresPenalty");
// 				}
//
// 				if (coresPenalty && !deathPenalty)
// 				{
// 					if (loseHandWeapon) // lose weapon on hand
// 					{
// 						const int weaponAttachPoints[] = { 0, 1 }; // weapon attachment points for both hands
//
// 						for (const int& weaponAttachPoint : weaponAttachPoints)
// 						{
// 							Hash weaponHash;
// 							if (WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponHash, false, weaponAttachPoint, true))
// 							{
// 								if (!Weapons::IsItem(weaponHash) && !Weapons::IsMelee(weaponHash)) // check first for weapon is item or melee
// 								{
// 									if (!loseExoticWeapon)
// 									{
// 										if (!Weapons::IsExotic(weaponHash)) // check for exotic if loseExoticWeapon is set to false
// 										{
// 											stringstream text;
// 											text << WEAPON::_GET_WEAPON_NAME(weaponHash) << " removed with ammo: " << WEAPON::GET_AMMO_IN_PED_WEAPON(playerPed, weaponHash);
// 											LOGGER.Write(text.str().c_str());
// 											WEAPON::_REMOVE_AMMO_FROM_PED_BY_TYPE(playerPed, WEAPON::GET_PED_AMMO_TYPE_FROM_WEAPON(playerPed, weaponHash), WEAPON::GET_AMMO_IN_PED_WEAPON(playerPed, weaponHash), 0x2188E0A3);
// 											WEAPON::REMOVE_WEAPON_FROM_PED(playerPed, weaponHash, true, NULL);
// 										}
// 									}
// 									else
// 									{
// 										stringstream text;
// 										text << WEAPON::_GET_WEAPON_NAME(weaponHash) << " removed with ammo: " << WEAPON::GET_AMMO_IN_PED_WEAPON(playerPed, weaponHash);
// 										LOGGER.Write(text.str().c_str());
// 										WEAPON::_REMOVE_AMMO_FROM_PED_BY_TYPE(playerPed, WEAPON::GET_PED_AMMO_TYPE_FROM_WEAPON(playerPed, weaponHash), WEAPON::GET_AMMO_IN_PED_WEAPON(playerPed, weaponHash), 0x2188E0A3);
// 										WEAPON::REMOVE_WEAPON_FROM_PED(playerPed, weaponHash, true, NULL);
// 									}
// 								}
// 							}
// 						}
// 					}
//
// 					if (loseBodyWeapon) // lose weapon on body
// 					{
// 						const int weaponAttachPoints[] = { 2, 3, 9, 10, 6 }; // all weapon attachment points on body
//
// 						for (const int& weaponAttachPoint : weaponAttachPoints)
// 						{
// 							Hash weaponHash;
// 							if (WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponHash, false, weaponAttachPoint, true))
// 							{
// 								if (!Weapons::IsItem(weaponHash) && !Weapons::IsMelee(weaponHash)) // check first for weapon is item or melee
// 								{
// 									if (weaponAttachPoint == 6)
// 									{
// 										if (Weapons::IsThrowableOnly(weaponHash)) // check thrower slot and ensure throwably exclusive only
// 										{
// 											if (!loseExoticWeapon)
// 											{
// 												if (!Weapons::IsExotic(weaponHash)) // check for exotic if loseExoticWeapon is set to false
// 												{
// 													stringstream text;
// 													text << WEAPON::_GET_WEAPON_NAME(weaponHash) << " removed with ammo: " << WEAPON::GET_AMMO_IN_PED_WEAPON(playerPed, weaponHash);
// 													LOGGER.Write(text.str().c_str());
// 													WEAPON::_REMOVE_AMMO_FROM_PED_BY_TYPE(playerPed, WEAPON::GET_PED_AMMO_TYPE_FROM_WEAPON(playerPed, weaponHash), WEAPON::GET_AMMO_IN_PED_WEAPON(playerPed, weaponHash), 0x2188E0A3);
// 													WEAPON::REMOVE_WEAPON_FROM_PED(playerPed, weaponHash, true, NULL);
// 												}
// 											}
// 											else
// 											{
// 												stringstream text;
// 												text << WEAPON::_GET_WEAPON_NAME(weaponHash) << " removed with ammo: " << WEAPON::GET_AMMO_IN_PED_WEAPON(playerPed, weaponHash);
// 												LOGGER.Write(text.str().c_str());
// 												WEAPON::_REMOVE_AMMO_FROM_PED_BY_TYPE(playerPed, WEAPON::GET_PED_AMMO_TYPE_FROM_WEAPON(playerPed, weaponHash), WEAPON::GET_AMMO_IN_PED_WEAPON(playerPed, weaponHash), 0x2188E0A3);
// 												WEAPON::REMOVE_WEAPON_FROM_PED(playerPed, weaponHash, true, NULL);
// 											}
// 										}
// 									}
// 									else
// 									{
// 										if (!loseExoticWeapon)
// 										{
// 											if (!Weapons::IsExotic(weaponHash)) // check for exotic if loseExoticWeapon is set to false
// 											{
// 												stringstream text;
// 												text << WEAPON::_GET_WEAPON_NAME(weaponHash) << " removed with ammo " << WEAPON::GET_AMMO_IN_PED_WEAPON(playerPed, weaponHash);
// 												LOGGER.Write(text.str().c_str());
// 												WEAPON::_REMOVE_AMMO_FROM_PED_BY_TYPE(playerPed, WEAPON::GET_PED_AMMO_TYPE_FROM_WEAPON(playerPed, weaponHash), WEAPON::GET_AMMO_IN_PED_WEAPON(playerPed, weaponHash), 0x2188E0A3);
// 												WEAPON::REMOVE_WEAPON_FROM_PED(playerPed, weaponHash, true, NULL);
// 											}
// 										}
// 										else
// 										{
// 											stringstream text;
// 											text << WEAPON::_GET_WEAPON_NAME(weaponHash) << " removed with ammo " << WEAPON::GET_AMMO_IN_PED_WEAPON(playerPed, weaponHash);
// 											LOGGER.Write(text.str().c_str());
// 											WEAPON::_REMOVE_AMMO_FROM_PED_BY_TYPE(playerPed, WEAPON::GET_PED_AMMO_TYPE_FROM_WEAPON(playerPed, weaponHash), WEAPON::GET_AMMO_IN_PED_WEAPON(playerPed, weaponHash), 0x2188E0A3);
// 											WEAPON::REMOVE_WEAPON_FROM_PED(playerPed, weaponHash, true, NULL);
// 										}
// 									}
// 								}
// 							}
// 						}
// 					}
//
// 					if (loseMoney)
// 					{
// 						int rngInt = MISC::GET_RANDOM_INT_IN_RANGE(lowestMoneyLose, highestMoneyLose);
// 						int finalMoney = (MONEY::_MONEY_GET_CASH_BALANCE() * rngInt / 100 <= 0) ? 0 : MONEY::_MONEY_GET_CASH_BALANCE() * rngInt / 100;
// 						MONEY::_MONEY_DECREMENT_CASH_BALANCE(finalMoney);
// 						stringstream text;
// 						text << "percentage of money to lose: " << rngInt << " % finalMoney: " << finalMoney;
// 						LOGGER.Write(text.str().c_str());
// 					}
// 					LOGGER.Write("hooked death penalty to player weapons, ammo and money applied");
// 					deathPenalty = true;
// 				}
//
// 				if (coresPenalty)
// 				{
// 					PLR.SetCore(Core::Health, 0);
// 					PLR.SetCore(Core::Stamina, 0);
// 					PLR.SetCore(Core::DeadEye, 0);
//
// 					ENTITY::_SET_ENTITY_HEALTH(playerPed, 1, 0);
// 					PLR.SetOuterCore(Core::Stamina, 1);
// 					PLR.SetOuterCore(Core::DeadEye, 1);
// 					coresPenalty = (World::GetGameTimer() - deathTime > 15000) ? false : true;
// 				}
//
// 				if (PLR.IsMoving() && PLR.IsAlive() && PLR.IsPlaying() && !coresPenalty && deathPenalty)
// 				{
// 					PLR.SetOuterCore(Core::Stamina, PLR.GetMaxOuterCore(Core::Stamina)); // restore outer core stamina until max
// 					PLR.SetOuterCore(Core::DeadEye, PLR.GetMaxOuterCore(Core::DeadEye)); // restore outer core  deadeye until max
// 					LOGGER.Write("hooked stopped applying death penalty to player cores");
// 				}
// 			}
// 			// END OF DEATH PENALTY +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		}
// 		// END OF CORE PART =====================================================================================================================
//
// 		// START DAMAGE AND NPC MODIFIER ========================================================================================================
// 		if (damageTweaks) // set damage modifier base on player health, basically the more health you got, the higher damager you take, the lower damage you give
// 		{
// 			if (Math::HealthAsPercentage(playerPed) > 80 && Math::HealthAsPercentage(playerPed) <= 100)
// 			{
// 				World::SetAIDamageModifier(aiDamageHighest * 0.5f, aiDamageHighest);
// 				PLR.SetDamageModifier(playerDamageLowest * 0.5f, playerDamageLowest);
// 			}
// 			else if (Math::HealthAsPercentage(playerPed) > 60 && Math::HealthAsPercentage(playerPed) <= 80)
// 			{
// 				World::SetAIDamageModifier(aiDamageHigh * 0.5f, aiDamageHigh);
// 				PLR.SetDamageModifier(playerDamageLow * 0.5f, playerDamageLow);
// 			}
// 			else if (Math::HealthAsPercentage(playerPed) > 40 && Math::HealthAsPercentage(playerPed) <= 60)
// 			{
// 				World::SetAIDamageModifier(aiDamageMedium * 0.5f, aiDamageMedium);
// 				PLR.SetDamageModifier(playerDamageMedium * 0.5f, playerDamageMedium);
// 			}
// 			else if (Math::HealthAsPercentage(playerPed) > 20 && Math::HealthAsPercentage(playerPed) <= 40)
// 			{
// 				World::SetAIDamageModifier(aiDamageLow * 0.5f, aiDamageLow);
// 				PLR.SetDamageModifier(playerDamageHigh * 0.5f, playerDamageHigh);
// 			}
// 			else if (Math::HealthAsPercentage(playerPed) > 0 && Math::HealthAsPercentage(playerPed) <= 20)
// 			{
// 				World::SetAIDamageModifier(aiDamageLowest * 0.5f, aiDamageLowest);
// 				PLR.SetDamageModifier(playerDamageHighest * 0.5f, playerDamageHighest);
// 			}
// 		}
//
// 		if (aiTweaks)
// 		{
// 			Ped peds[1024];
// 			int count = worldGetAllPeds(peds, pedsRange); // get all peds within range and do stuffs
//
// 			if (aiRegen)
// 			{
// 				for (int i = 0; i < count; i++)
// 				{
// 					if (aiRegenMap.find(peds[i]) == aiRegenMap.end()) aiRegenMap[peds[i]] = 0;
// 					if (aiHealMap.find(peds[i]) == aiHealMap.end()) aiHealMap[peds[i]] = 0;
// 				}
// 			}
//
// 			for (int i = 0; i < count; i++)
// 			{
// 				if (peds[i] != playerPed && PED::IS_PED_HUMAN(peds[i]) && !PED::IS_PED_DEAD_OR_DYING(peds[i], true) && ENTITY::DOES_ENTITY_EXIST(peds[i]))
// 				{
// 					if (Math::HealthAsPercentage(peds[i]) > 80 && Math::HealthAsPercentage(peds[i]) <= 100)
// 					{
// 						if (aiAccuracy) PED::SET_PED_ACCURACY(peds[i], aiHighestAccuracy); // accuracy
// 						if (aiShootRate) PED::SET_PED_SHOOT_RATE(peds[i], aiHighestShootRate); // shoot rate
// 						if (aiRegen) aiRegenMap[peds[i]] = aiLowestRegen * 100 / ENTITY::GET_ENTITY_MAX_HEALTH(peds[i], 0);
// 					}
// 					else if (Math::HealthAsPercentage(peds[i]) > 60 && Math::HealthAsPercentage(peds[i]) <= 80)
// 					{
// 						if (aiAccuracy) PED::SET_PED_ACCURACY(peds[i], aiHighAccuracy);
// 						if (aiShootRate) PED::SET_PED_SHOOT_RATE(peds[i], aiHighShootRate);
// 						if (aiRegen) aiRegenMap[peds[i]] = aiLowRegen * 100 / ENTITY::GET_ENTITY_MAX_HEALTH(peds[i], 0);
// 					}
// 					else if (Math::HealthAsPercentage(peds[i]) > 40 && Math::HealthAsPercentage(peds[i]) <= 60)
// 					{
// 						if (aiAccuracy) PED::SET_PED_ACCURACY(peds[i], aiMediumAccuracy);
// 						if (aiShootRate) PED::SET_PED_SHOOT_RATE(peds[i], aiMediumShootRate);
// 						if (aiRegen) aiRegenMap[peds[i]] = aiMediumRegen * 100 / ENTITY::GET_ENTITY_MAX_HEALTH(peds[i], 0);
// 					}
// 					else if (Math::HealthAsPercentage(peds[i]) > 20 && Math::HealthAsPercentage(peds[i]) <= 40)
// 					{
// 						if (aiAccuracy) PED::SET_PED_ACCURACY(peds[i], aiLowAccuracy);
// 						if (aiShootRate) PED::SET_PED_SHOOT_RATE(peds[i], aiLowShootRate);
// 						if (aiRegen) aiRegenMap[peds[i]] = aiHighRegen * 100 / ENTITY::GET_ENTITY_MAX_HEALTH(peds[i], 0);
// 					}
// 					else if (Math::HealthAsPercentage(peds[i]) > 0 && Math::HealthAsPercentage(peds[i]) <= 20)
// 					{
// 						if (aiAccuracy) PED::SET_PED_ACCURACY(peds[i], aiLowestAccuracy);
// 						if (aiShootRate) PED::SET_PED_SHOOT_RATE(peds[i], aiLowestShootRate);
// 						if (aiRegen) aiRegenMap[peds[i]] = aiLowestRegen * 100 / ENTITY::GET_ENTITY_MAX_HEALTH(peds[i], 0);
// 					}
//
// 					if (aiRegen)
// 					{
// 						if (ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ANY_PED(peds[i]) || ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ANY_OBJECT(peds[i]))
// 						{
// 							aiHealMap[peds[i]] = World::GetGameTimer() + aiHealMs; // time ai is damaged
//
// 							if (World::GetGameTimer() - aiHealMap[peds[i]] >= aiHealMs) // current game time minus time ai is damaged more than aiHealMs
// 							{
// 								if (PED::IS_PED_IN_MELEE_COMBAT(peds[i])) // melee combat check so they can actually be taken down, still heal tho
// 								{
// 									if ((ENTITY::GET_ENTITY_HEALTH(peds[i]) + (aiRegenMap[peds[i]] * 0.1f)) < ENTITY::GET_ENTITY_MAX_HEALTH(peds[i], 0))
// 									{
// 										ENTITY::_SET_ENTITY_HEALTH(peds[i], Math::Floor(ENTITY::GET_ENTITY_HEALTH(peds[i]) + (aiRegenMap[peds[i]] * 0.1f)), 0); // slowed regen for melee combat
// 									}
// 									else
// 									{
// 										ENTITY::_SET_ENTITY_HEALTH(peds[i], (ENTITY::GET_ENTITY_MAX_HEALTH(peds[i], 0)), 0); // set max health
// 									}
// 								}
// 								else if (!PED::IS_PED_IN_MELEE_COMBAT(peds[i]))
// 								{
// 									if ((ENTITY::GET_ENTITY_HEALTH(peds[i]) + aiRegenMap[peds[i]]) < ENTITY::GET_ENTITY_MAX_HEALTH(peds[i], 0))
// 									{
// 										ENTITY::_SET_ENTITY_HEALTH(peds[i], (ENTITY::GET_ENTITY_HEALTH(peds[i]) + aiRegenMap[peds[i]]), 0); // normal regen
// 									}
// 									else
// 									{
// 										ENTITY::_SET_ENTITY_HEALTH(peds[i], (ENTITY::GET_ENTITY_MAX_HEALTH(peds[i], 0)), 0); // set max health
// 										PED::CLEAR_PED_BLOOD_DAMAGE(peds[i]);
// 										for (int j = 0; j < 10; j++)
// 										{
// 											PED::_CLEAR_PED_BLOOD_DAMAGE_FACIAL(peds[i], j);
// 										}
// 									}
// 								}
// 							}
// 						}
// 					}
// 				}
// 			}
// 		}
// 		// END DAMAGE AND NPC MODIFIER ==========================================================================================================
//
// 		WAIT(0);
// 	}
// 	return (0);
// }
