#include "SoftCores/Config.h"
#include "SoftCores/Enums.h"
#include <cwctype>

using namespace SoftCores;

unsigned int Config::GetConfigUInt(const std::wstring &section, const std::wstring &key, const std::wstring &def) const
{
	constexpr unsigned char	buffSize = 32;
	wchar_t					buff[buffSize]{};

	GetPrivateProfileStringW(section.c_str(), key.c_str(), def.c_str(), buff, buffSize, File.c_str());
	Logger->Write((std::wstring(
		L"INI value for key \'") + key + L"\' = [" + buff + L"]"
		).c_str());
	try
	{
		return (static_cast<unsigned int>(std::stol(buff)));
	}
	catch (std::exception)
	{
		Logger->Write(L"INI read failed, using default.");
		return (static_cast<unsigned int>(std::stol(def)));
	}
}

float Config::GetConfigFloat(const std::wstring &section, const std::wstring &key, const std::wstring &def) const
{
	constexpr unsigned char	buffSize = 32;
	wchar_t					buff[buffSize]{};

	GetPrivateProfileStringW(section.c_str(), key.c_str(), def.c_str(), buff, buffSize, File.c_str());
	Logger->Write((std::wstring(
		L"INI value for key \'") + key + L"\' = [" + buff + L"]"
		).c_str());
	try
	{
		return (stof(std::wstring(buff)));
	}
	catch (std::exception)
	{
		Logger->Write(L"INI read failed, using default.");
		return (stof(def));
	}
}

bool Config::GetConfigBool(const std::wstring &section, const std::wstring &key, const std::wstring &def) const
{
	constexpr unsigned char	buffSize = 32;
	wchar_t					buff[buffSize]{};
	unsigned char			i;

	GetPrivateProfileStringW(section.c_str(), key.c_str(), def.c_str(), buff, buffSize, File.c_str());
	Logger->Write((std::wstring(
		L"INI value for key \'") + key + L"\' = [" + buff + L"]"
		).c_str());
	for (i = 0; i <= buffSize || !buff[i]; i++)
		buff[i] = std::towlower(buff[i]);
	return (std::wstring(buff) == L"true");
}

Config::Config(const std::wstring &filename, Util::Logger &logger)
{
	const wchar_t	*DebugSect =		L"DEBUG";
	const wchar_t	*FXSect =			L"VANILLA_FX";
	const wchar_t	*ImmersionSect =	L"IMMERSION";
	const wchar_t	*CoreDepSect =		L"CORE_DEPLETION";
	const wchar_t	*HorseCoreDepSect =	L"HORSE_CORE_DEPLETION";
	const wchar_t	*TempSect =			L"TEMPERATURE";
	const wchar_t	*DyingPenaltySect =	L"PENALTY_ON_DEATH";
	const wchar_t	*PlayerTweaksSect =	L"PLAYER_COMBAT_TWEAKS";
	const wchar_t	*AITweaksSect =		L"AI_COMBAT_TWEAKS";

	Logger = &logger;
	File = filename;
	// Default floats only have 1 decimal to identify them in the log.
	AdvancedLoggingEnabled = GetConfigBool(DebugSect, L"DebugAdvancedLogging", L"false");
	FX = {
		.Enabled =		GetConfigBool(FXSect, L"FXOverrideEnabled", L"true"),
		.EmptyHealth =	GetConfigBool(FXSect, L"EmptyHealthCoreFX", L"true"),
		.EmptyStamina =	GetConfigBool(FXSect, L"EmptyStaminaCoreFX", L"true"),
		.EmptyDeadEye =	GetConfigBool(FXSect, L"EmptyDeadeyeCoreFX", L"true"),
		.Overpower =	GetConfigBool(FXSect, L"OverpoweredCoreFX", L"true"),
		.Duel =			GetConfigBool(FXSect, L"DuelFX", L"true"),
		.Deadeye =		GetConfigBool(FXSect, L"DeadeyeFX", L"true"),
		.Eagleeye =		GetConfigBool(FXSect, L"EagleeyeFX", L"true"),
		.WeaponWheel =	GetConfigBool(FXSect, L"WeaponWheelFX", L"false"),
		.KillCam =		GetConfigBool(FXSect, L"KillCamFX", L"false"),
		.Death =		GetConfigBool(FXSect, L"DeathFX", L"false"),
		.MissionFail =	GetConfigBool(FXSect, L"MissionFailFX", L"false")
	};

	Immersion = {
		.DisablePickupGlow =			GetConfigBool(ImmersionSect, L"DisablePickupGlow", L"true"),
		.DisableObjectGlow =			GetConfigBool(ImmersionSect, L"DisableObjectGlow", L"true"),
		.HideHostileBlips =				GetConfigBool(ImmersionSect, L"HideHostileBlipsOutOfView", L"true"),
		.HideHostileBlipsInMissions =	GetConfigBool(ImmersionSect, L"HideHostileBlipsOutOfViewInMissions", L"false"),
		.NoReloadInDeadeye =			GetConfigBool(ImmersionSect, L"NoReloadInDeadeye", L"true"),
		.SleepOnlyRestoresStamina =		GetConfigBool(ImmersionSect, L"SleepOnlyRestoresStamina", L"true"),
		.BathOnlyRestoresDeadeye =		GetConfigBool(ImmersionSect, L"BathOnlyRestoresDeadeye", L"true")
	};

	PlayerDepletion = {
		.Enabled =						GetConfigBool(CoreDepSect, L"CoreDepletion", L"true"),
		.NaturalEnabled =				GetConfigBool(CoreDepSect, L"NaturalCoreDepletion", L"true"),
		.TemperatureEnabled =			GetConfigBool(CoreDepSect, L"TemperatureDepletion", L"true"),
		.HealthCoreEmptyEnabled =		GetConfigBool(CoreDepSect, L"HealthCoreEmptyDepletion", L"true"),
		.HealthCoreEmptyDrainEnabled =	GetConfigBool(CoreDepSect, L"HealthCoreEmptyDrain", L"true"),
		.AimStaminaDrainEnabled =		GetConfigBool(CoreDepSect, L"AimingStaminaDrain", L"false"),
		.AimDeadeyeDrainEnabled =		GetConfigBool(CoreDepSect, L"AimingDeadeyeDrain", L"false"),
		.Base =							GetConfigFloat(CoreDepSect, L"BaseDepletionRate", L"1.0"),
		.Health =						GetConfigFloat(CoreDepSect, L"HealthCoreDepletionRate", L"0.9"),
		.Stamina =						GetConfigFloat(CoreDepSect, L"StaminaCoreDepletionRate", L"1.0"),
		.Deadeye =						GetConfigFloat(CoreDepSect, L"DeadeyeCoreDepletionRate", L"0.7"),
		.Natural =						GetConfigFloat(CoreDepSect, L"NaturalCoreDepletionRate", L"1.0"),
		.Temperature =					GetConfigFloat(CoreDepSect, L"TemperatureDepletionRate", L"1.1"),
		.HealthCoreEmpty =				GetConfigFloat(CoreDepSect, L"HealthCoreEmptyDepletionRate", L"2.0"),
		.HealthCoreDrain =				GetConfigFloat(CoreDepSect, L"HealthCoreDrainRate", L"1.0"),
		.AimStaminaDrain =				GetConfigFloat(CoreDepSect, L"AimingStaminaDrainRate", L"1.0"),
		.AimDeadeyeDrain =				GetConfigFloat(CoreDepSect, L"AimingDeadeyeDrainRate", L"1.0")
	};

	HorseDepletion = {
		.Enabled =					GetConfigBool(HorseCoreDepSect, L"HorseCoreDepletion", L"true"),
		.NaturalEnabled =			GetConfigBool(HorseCoreDepSect, L"HorseNaturalCoreDepletion", L"true"),
		.HealthCoreEmptyEnabled =	GetConfigBool(HorseCoreDepSect, L"HorseHealthCoreEmptyDepletion", L"true"),
		.Base =						GetConfigFloat(HorseCoreDepSect, L"HorseNaturalCoreDepletionRate", L"1.0"),
		.Natural =					GetConfigFloat(HorseCoreDepSect, L"HorseHealthCoreDepletionRate", L"0.9"),
		.Health =					GetConfigFloat(HorseCoreDepSect, L"HorseStaminaCoreDepletionRate", L"1.0"),
		.Stamina =					GetConfigFloat(HorseCoreDepSect, L"HorseNaturalCoreDepletionRate", L"1.0"),
		.HealthCoreEmpty =			GetConfigFloat(HorseCoreDepSect, L"HorseHealthCoreEmptyDepletionRate", L"2.0"),
	};

	Temperature = {
		.ExtremeFX =			GetConfigBool(TempSect, L"ExtremeTemperatureFX", L"true"),
		.ExtremeSprite =		GetConfigBool(TempSect, L"ExtremeTemperatureSprite", L"true"),
		.WarmthFire =			GetConfigFloat(TempSect, L"WarmthFire", L"1.0"),
		.WarmthCampfire =		GetConfigFloat(TempSect, L"WarmthCampfire", L"1.0"),
		.WarmthIndoors =		GetConfigFloat(TempSect, L"WarmthIndoors", L"1.0"),
		.ColdSubmerged =		GetConfigFloat(TempSect, L"ColdSubmerged", L"1.0"),
		.ColdRaining =			GetConfigFloat(TempSect, L"ColdRaining", L"1.0"),
		.ColdSnowing =			GetConfigFloat(TempSect, L"ColdSnowing", L"1.2"),
		.FreezingThreshold =	GetConfigFloat(TempSect, L"FreezingThreshold", L"1.0"),
		.HotThreshold =			GetConfigFloat(TempSect, L"HotThreshold", L"1.0")
	};

	DyingPenalty = {
		.Enabled =				GetConfigBool(DyingPenaltySect, L"PenaltyOnDeath", L"true"),
		.LoseHeldWeapon =		GetConfigBool(DyingPenaltySect, L"LoseHeldWeapon", L"false"),
		.LoseHeldAmmo =			GetConfigBool(DyingPenaltySect, L"LoseHeldAmmo", L"false"),
		.LoseBodyWeapons =		GetConfigBool(DyingPenaltySect, L"LoseBodyWeapons", L"false"),
		.LoseBodyAmmo =			GetConfigBool(DyingPenaltySect, L"LoseBodyAmmo", L"false"),
		.LoseExoticWeapons =	GetConfigBool(DyingPenaltySect, L"LoseExoticWeapons", L"false"),
		.LoseMoney =			GetConfigBool(DyingPenaltySect, L"LoseMoney", L"true"),
		.LoseMoneyMin =			GetConfigFloat(DyingPenaltySect, L"LoseMoneyMin", L"0.9"),
		.LoseMoneyMax =			GetConfigFloat(DyingPenaltySect, L"LoseMoneyMax", L"0.98"),
		.LoseMoneyHardMin =		GetConfigUInt(DyingPenaltySect, L"LoseMoneyHardMax", L"1000000"),
		.LoseMoneyHardMax =		GetConfigUInt(DyingPenaltySect, L"LoseMoneyHardMin", L"0")
	};

	PlayerTweaks = {
		.Enabled =			GetConfigBool(PlayerTweaksSect, L"PlayerCombatTweaks", L"false"),
		.DamageMaxHealth =	GetConfigFloat(PlayerTweaksSect, L"PlayerDamageMaxHealth", L"1.0"),
		.DamageMinHealth =	GetConfigFloat(PlayerTweaksSect, L"PlayerDamageMinHealth", L"0.5")
	};

	AITweaks = {
		.Enabled =						GetConfigBool(AITweaksSect, L"AICombatTweaks", L"false"),
		.DamageEnabled =				GetConfigBool(AITweaksSect, L"AIDamageTweaks", L"false"),
		.RegenEnabled =					GetConfigBool(AITweaksSect, L"AIHealthRegeneration", L"false"),
		.AccuracyEnabled =				GetConfigBool(AITweaksSect, L"AIAccuracyTweaks", L"false"),
		.AccuracyInMissionsEnabled =	GetConfigBool(AITweaksSect, L"AIAccuracyTweaksInMissions", L"false"),
		.FirerateEnabled =				GetConfigBool(AITweaksSect, L"AIFirerateTweaks", L"false"),
		.DamageMaxHealth =				GetConfigFloat(AITweaksSect, L"AIDamageMaxHealth", L"1.0"),
		.DamageMinHealth =				GetConfigFloat(AITweaksSect, L"AIDamageMinHealth", L"1.0"),
		.RegenMaxHealth =				GetConfigFloat(AITweaksSect, L"AIHealthRegenerationMaxHealth", L"1.0"),
		.RegenMinHealth =				GetConfigFloat(AITweaksSect, L"AIHealthRegenerationMinHealth", L"1.0"),
		.AccuracyMaxHealth =			GetConfigFloat(AITweaksSect, L"AIAccuracyMaxHealth", L"1.0"),
		.AccuracyMinHealth =			GetConfigFloat(AITweaksSect, L"AIAccuracyMinHealth", L"1.0"),
		.FirerateMaxHealth =			GetConfigFloat(AITweaksSect, L"AIFirerateMaxHealth", L"1.0"),
		.FirerateMinHealth =			GetConfigFloat(AITweaksSect, L"AIFirerateMinHealth", L"1.0")
	};
}
