#include "SoftCores/Config.h"

using namespace SoftCores;

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
	// Default bools end with an uppercase letter to indentify those.
	AdvancedLoggingEnabled = GetConfig<bool>(DebugSect, L"DebugAdvancedLogging", L"falsE");
	FX = {
		.Enabled =		GetConfig<bool>(FXSect, L"FXOverrideEnabled", L"truE"),
		.EmptyHealth =	GetConfig<bool>(FXSect, L"EmptyHealthCoreFX", L"truE"),
		.EmptyStamina =	GetConfig<bool>(FXSect, L"EmptyStaminaCoreFX", L"truE"),
		.EmptyDeadEye =	GetConfig<bool>(FXSect, L"EmptyDeadeyeCoreFX", L"truE"),
		.Overpower =	GetConfig<bool>(FXSect, L"OverpoweredCoreFX", L"truE"),
		.Duel =			GetConfig<bool>(FXSect, L"DuelFX", L"truE"),
		.Deadeye =		GetConfig<bool>(FXSect, L"DeadeyeFX", L"truE"),
		.Eagleeye =		GetConfig<bool>(FXSect, L"EagleeyeFX", L"truE"),
		.WeaponWheel =	GetConfig<bool>(FXSect, L"WeaponWheelFX", L"falsE"),
		.KillCam =		GetConfig<bool>(FXSect, L"KillCamFX", L"falsE"),
		.Death =		GetConfig<bool>(FXSect, L"DeathFX", L"falsE"),
		.MissionFail =	GetConfig<bool>(FXSect, L"MissionFailFX", L"falsE")
	};

	Immersion = {
		.DisablePickupGlow =			GetConfig<bool>(ImmersionSect, L"DisablePickupGlow", L"truE"),
		.DisableObjectGlow =			GetConfig<bool>(ImmersionSect, L"DisableObjectGlow", L"truE"),
		.HideHostileBlips =				GetConfig<bool>(ImmersionSect, L"HideHostileBlipsOutOfView", L"truE"),
		.HideHostileBlipsInMissions =	GetConfig<bool>(ImmersionSect, L"HideHostileBlipsOutOfViewInMissions", L"falsE"),
		.NoReloadInDeadeye =			GetConfig<bool>(ImmersionSect, L"NoReloadInDeadeye", L"truE"),
		.SleepOnlyRestoresStamina =		GetConfig<bool>(ImmersionSect, L"SleepOnlyRestoresStamina", L"truE"),
		.BathOnlyRestoresDeadeye =		GetConfig<bool>(ImmersionSect, L"BathOnlyRestoresDeadeye", L"truE")
	};

	PlayerDepletion = {
		.Enabled =						GetConfig<bool>(CoreDepSect, L"CoreDepletion", L"truE"),
		.NaturalEnabled =				GetConfig<bool>(CoreDepSect, L"NaturalCoreDepletion", L"truE"),
		.TemperatureEnabled =			GetConfig<bool>(CoreDepSect, L"TemperatureDepletion", L"truE"),
		.HealthCoreEmptyEnabled =		GetConfig<bool>(CoreDepSect, L"HealthCoreEmptyDepletion", L"truE"),
		.HealthCoreEmptyDrainEnabled =	GetConfig<bool>(CoreDepSect, L"HealthCoreEmptyDrain", L"truE"),
		.AimStaminaDrainEnabled =		GetConfig<bool>(CoreDepSect, L"AimingStaminaDrain", L"falsE"),
		.AimDeadeyeDrainEnabled =		GetConfig<bool>(CoreDepSect, L"AimingDeadeyeDrain", L"falsE"),
		.Base =							GetConfig<float>(CoreDepSect, L"BaseDepletionRate", L"1.0"),
		.Health =						GetConfig<float>(CoreDepSect, L"HealthCoreDepletionRate", L"0.9"),
		.Stamina =						GetConfig<float>(CoreDepSect, L"StaminaCoreDepletionRate", L"1.0"),
		.Deadeye =						GetConfig<float>(CoreDepSect, L"DeadeyeCoreDepletionRate", L"0.7"),
		.Natural =						GetConfig<float>(CoreDepSect, L"NaturalCoreDepletionRate", L"1.0"),
		.Temperature =					GetConfig<float>(CoreDepSect, L"TemperatureDepletionRate", L"1.1"),
		.HealthCoreEmpty =				GetConfig<float>(CoreDepSect, L"HealthCoreEmptyDepletionRate", L"2.0"),
		.HealthCoreDrain =				GetConfig<float>(CoreDepSect, L"HealthCoreDrainRate", L"1.0"),
		.AimStaminaDrain =				GetConfig<float>(CoreDepSect, L"AimingStaminaDrainRate", L"1.0"),
		.AimDeadeyeDrain =				GetConfig<float>(CoreDepSect, L"AimingDeadeyeDrainRate", L"1.0")
	};

	HorseDepletion = {
		.Enabled =					GetConfig<bool>(HorseCoreDepSect, L"HorseCoreDepletion", L"truE"),
		.NaturalEnabled =			GetConfig<bool>(HorseCoreDepSect, L"HorseNaturalCoreDepletion", L"truE"),
		.HealthCoreEmptyEnabled =	GetConfig<bool>(HorseCoreDepSect, L"HorseHealthCoreEmptyDepletion", L"truE"),
		.Base =						GetConfig<float>(HorseCoreDepSect, L"HorseNaturalCoreDepletionRate", L"1.0"),
		.Natural =					GetConfig<float>(HorseCoreDepSect, L"HorseHealthCoreDepletionRate", L"0.9"),
		.Health =					GetConfig<float>(HorseCoreDepSect, L"HorseStaminaCoreDepletionRate", L"1.0"),
		.Stamina =					GetConfig<float>(HorseCoreDepSect, L"HorseNaturalCoreDepletionRate", L"1.0"),
		.HealthCoreEmpty =			GetConfig<float>(HorseCoreDepSect, L"HorseHealthCoreEmptyDepletionRate", L"2.0"),
	};

	Temperature = {
		.ExtremeFX =			GetConfig<bool>(TempSect, L"ExtremeTemperatureFX", L"truE"),
		.ExtremeSprite =		GetConfig<bool>(TempSect, L"ExtremeTemperatureSprite", L"truE"),
		.WarmthFire =			GetConfig<float>(TempSect, L"WarmthFire", L"1.0"),
		.WarmthCampfire =		GetConfig<float>(TempSect, L"WarmthCampfire", L"1.0"),
		.WarmthIndoors =		GetConfig<float>(TempSect, L"WarmthIndoors", L"1.0"),
		.ColdSubmerged =		GetConfig<float>(TempSect, L"ColdSubmerged", L"1.0"),
		.ColdRaining =			GetConfig<float>(TempSect, L"ColdRaining", L"1.0"),
		.ColdSnowing =			GetConfig<float>(TempSect, L"ColdSnowing", L"1.2"),
		.FreezingThreshold =	GetConfig<float>(TempSect, L"FreezingThreshold", L"1.0"),
		.HotThreshold =			GetConfig<float>(TempSect, L"HotThreshold", L"1.0")
	};

	DyingPenalty = {
		.Enabled =				GetConfig<bool>(DyingPenaltySect, L"PenaltyOnDeath", L"truE"),
		.LoseHeldWeapon =		GetConfig<bool>(DyingPenaltySect, L"LoseHeldWeapon", L"falsE"),
		.LoseHeldAmmo =			GetConfig<bool>(DyingPenaltySect, L"LoseHeldAmmo", L"falsE"),
		.LoseBodyWeapons =		GetConfig<bool>(DyingPenaltySect, L"LoseBodyWeapons", L"falsE"),
		.LoseBodyAmmo =			GetConfig<bool>(DyingPenaltySect, L"LoseBodyAmmo", L"falsE"),
		.LoseExoticWeapons =	GetConfig<bool>(DyingPenaltySect, L"LoseExoticWeapons", L"falsE"),
		.LoseMoney =			GetConfig<bool>(DyingPenaltySect, L"LoseMoney", L"truE"),
		.LoseMoneyMin =			GetConfig<float>(DyingPenaltySect, L"LoseMoneyMin", L"0.9"),
		.LoseMoneyMax =			GetConfig<float>(DyingPenaltySect, L"LoseMoneyMax", L"0.8"),
		.LoseMoneyHardMin =		GetConfig<unsigned int>(DyingPenaltySect, L"LoseMoneyHardMax", L"1000000"),
		.LoseMoneyHardMax =		GetConfig<unsigned int>(DyingPenaltySect, L"LoseMoneyHardMin", L"0")
	};

	PlayerTweaks = {
		.Enabled =			GetConfig<bool>(PlayerTweaksSect, L"PlayerCombatTweaks", L"falsE"),
		.DamageMaxHealth =	GetConfig<float>(PlayerTweaksSect, L"PlayerDamageMaxHealth", L"1.0"),
		.DamageMinHealth =	GetConfig<float>(PlayerTweaksSect, L"PlayerDamageMinHealth", L"0.5")
	};

	AITweaks = {
		.Enabled =						GetConfig<bool>(AITweaksSect, L"AICombatTweaks", L"falsE"),
		.DamageEnabled =				GetConfig<bool>(AITweaksSect, L"AIDamageTweaks", L"falsE"),
		.RegenEnabled =					GetConfig<bool>(AITweaksSect, L"AIHealthRegeneration", L"falsE"),
		.AccuracyEnabled =				GetConfig<bool>(AITweaksSect, L"AIAccuracyTweaks", L"falsE"),
		.AccuracyInMissionsEnabled =	GetConfig<bool>(AITweaksSect, L"AIAccuracyTweaksInMissions", L"falsE"),
		.FirerateEnabled =				GetConfig<bool>(AITweaksSect, L"AIFirerateTweaks", L"falsE"),
		.DamageMaxHealth =				GetConfig<float>(AITweaksSect, L"AIDamageMaxHealth", L"1.0"),
		.DamageMinHealth =				GetConfig<float>(AITweaksSect, L"AIDamageMinHealth", L"1.0"),
		.RegenMaxHealth =				GetConfig<float>(AITweaksSect, L"AIHealthRegenerationMaxHealth", L"1.0"),
		.RegenMinHealth =				GetConfig<float>(AITweaksSect, L"AIHealthRegenerationMinHealth", L"1.0"),
		.AccuracyMaxHealth =			GetConfig<float>(AITweaksSect, L"AIAccuracyMaxHealth", L"1.0"),
		.AccuracyMinHealth =			GetConfig<float>(AITweaksSect, L"AIAccuracyMinHealth", L"1.0"),
		.FirerateMaxHealth =			GetConfig<float>(AITweaksSect, L"AIFirerateMaxHealth", L"1.0"),
		.FirerateMinHealth =			GetConfig<float>(AITweaksSect, L"AIFirerateMinHealth", L"1.0")
	};
}
