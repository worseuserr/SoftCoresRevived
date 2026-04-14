#pragma once

#include <string>
#include <cwctype>
#include <windows.h>
#include "Util/Logger.h"

namespace SoftCores
{
	using	Multiplier = float;

	struct	FXConfig
	{
		// Master control, if false, no base game effects are disabled.
		bool	Enabled;
		bool	EmptyHealth;
		bool	EmptyStamina;
		bool	EmptyDeadEye;
		bool	Overpower;
		bool	Duel;
		bool	Deadeye;
		bool	Eagleeye;
		bool	WeaponWheel;
		bool	KillCam;
		bool	Death;
		bool	MissionFail;
	};

	struct	ImmersionConfig
	{
		bool	DisablePickupGlow;
		bool	DisableObjectGlow;
		bool	HideOutOfViewBlips;
		bool	HideOutOfViewBlipsOnlyHostile;
		bool	HideOutOfViewBlipsInMissions;
		bool	HideOutOfViewBlipsForCorpses;
		bool	NoReloadInDeadeye;
		bool	SleepOnlyRestoresStamina;
		bool	BathOnlyRestoresDeadeye;
	};

	struct	CoreDepletionConfig
	{
		bool		Enabled;
		bool		NaturalEnabled;
		bool		TemperatureEnabled;
		bool		HealthCoreEmptyEnabled;
		bool		HealthCoreEmptyDrainEnabled;
		bool		AimStaminaDrainEnabled;
		bool		AimDeadeyeDrainEnabled;
		Multiplier	Base;
		Multiplier	Health;
		Multiplier	Stamina;
		Multiplier	Deadeye;
		Multiplier	Natural;
		Multiplier	Temperature;
		Multiplier	HealthCoreEmpty;
		Multiplier	HealthCoreDrain;
		Multiplier	AimStaminaDrain;
		Multiplier	AimDeadeyeDrain;
	};

	struct	HorseCoreDepletionConfig
	{
		bool		Enabled;
		bool		NaturalEnabled;
		bool		HealthCoreEmptyEnabled;
		Multiplier	Base;
		Multiplier	Natural;
		Multiplier	Health;
		Multiplier	Stamina;
		Multiplier	HealthCoreEmpty;
	};

	struct	TemperatureConfig
	{
		bool		ExtremeFX;
		bool		ExtremeSprite;
		Multiplier	WarmthFire;
		Multiplier	WarmthCampfire;
		Multiplier	WarmthIndoors;
		Multiplier	ColdSubmerged;
		Multiplier	ColdRaining;
		Multiplier	ColdSnowing;
		Multiplier	FreezingThreshold;
		Multiplier	HotThreshold;
	};

	struct	DyingPenaltyConfig
	{
		bool			Enabled;
		bool			LoseHeldWeapon;
		bool			LoseHeldAmmo;
		bool			LoseBodyWeapons;
		bool			LoseBodyAmmo;
		bool			LoseExoticWeapons;
		bool			LoseMoney;
		Multiplier		LoseMoneyMin;
		Multiplier		LoseMoneyMax;
		unsigned int	LoseMoneyHardMin;
		unsigned int	LoseMoneyHardMax;
	};

	struct	PlayerTweakConfig
	{
		bool		Enabled;
		Multiplier	DamageMaxHealth;
		Multiplier	DamageMinHealth;
	};

	struct	AITweakConfig
	{
		bool		Enabled;
		bool		DamageEnabled;
		bool		RegenEnabled;
		bool		AccuracyEnabled;
		bool		AccuracyInMissionsEnabled;
		bool		FirerateEnabled;
		Multiplier	DamageMaxHealth;
		Multiplier	DamageMinHealth;
		Multiplier	RegenMaxHealth;
		Multiplier	RegenMinHealth;
		Multiplier	AccuracyMaxHealth;
		Multiplier	AccuracyMinHealth;
		Multiplier	FirerateMaxHealth;
		Multiplier	FirerateMinHealth;
	};

	// Config values for SoftCoresRevived.
	class	Config
	{
		std::wstring	File;

	public:
		Util::Logger	*Logger;

		Config(const std::wstring &filename, Util::Logger &logger);

		template <typename T>
		requires (std::same_as<T, bool>
			|| std::same_as<T, unsigned int>
			|| std::same_as<T, float>)
		T							GetConfig(const std::wstring &section, const std::wstring &key, const std::wstring &def) const;

		// Toggles for base game effects.
		FXConfig					FX;

		// Toggles for additional immersive mod features.
		ImmersionConfig				Immersion;

		// Config for player core depletion.
		CoreDepletionConfig			PlayerDepletion;

		// Config for player horse core depletion.
		HorseCoreDepletionConfig	HorseDepletion;

		// Config for temperature mechanics.
		TemperatureConfig			Temperature;

		// Config for penalties on death.
		DyingPenaltyConfig			DyingPenalty;

		// Config for player tweaks.
		PlayerTweakConfig			PlayerTweaks;

		// Config for AI tweaks.
		AITweakConfig				AITweaks;

		// Range of peds to go through, lowerable for performance.
		short						PedRange;

		// Force set loglevel to debug + toggle ingame logging.
		bool						ForceDebugLogging;
		bool						IngameDebugLogging;
	};

	template <typename T>
	requires (std::same_as<T, bool>
	|| std::same_as<T, unsigned int>
	|| std::same_as<T, float>)
	T	Config::GetConfig(const std::wstring &section, const std::wstring &key, const std::wstring &def) const
	{
		constexpr unsigned char	buffSize = 32;
		wchar_t					buff[buffSize]{};
		unsigned char			i;

		GetPrivateProfileStringW(section.c_str(), key.c_str(), def.c_str(), buff, buffSize, File.c_str());
		Logger->Write((std::wstring(
			L"INI value for key \'") + key + L"\' = [" + buff + L"]"
			).c_str());
		if constexpr (std::same_as<T, bool>)
		{
			for (i = 0; i < buffSize && buff[i]; i++)
				buff[i] = std::towlower(buff[i]);
			return (std::wstring(buff) == L"true");
		}
		if constexpr (std::same_as<T, unsigned int>)
		{
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
		if constexpr (std::same_as<T, float>)
		{
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
		// All exceptions will eventually be replaced with a custom error function.
		throw std::exception();
	}
}
