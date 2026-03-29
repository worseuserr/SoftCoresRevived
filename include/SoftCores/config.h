#pragma once
#include <string>

using Multiplier = float;

namespace SoftCores
{
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
		// The feature that hides hostile blips outside of the player's view.
		bool	HideHostileBlips;
		bool	HideHostileBlipsInMissions;
		bool	NoReloadInDeadeye;
		bool	SleepOnlyRestoresStamina;
		bool	BathOnlyRestoresDeadeye;
	};

	struct	CoreDepletionConfig
	{
		bool		Enabled;
		bool		NaturalEnabled;
		bool		TemperatureEnabled;
		bool		BleedoutEnabled;
		bool		AimStaminaEnabled;
		bool		AimDeadeyeEnabled;
		Multiplier	Natural;
		Multiplier	Health;
		Multiplier	Stamina;
		Multiplier	Deadeye;
		Multiplier	ExtremeTemperature;
		Multiplier	HealthCoreEmpty;
		Multiplier	HealthCoreBleedout;
		Multiplier	AimStamina;
		Multiplier	AimDeadeye;
	};

	struct	HorseCoreDepletionConfig
	{
		bool		Enabled;
		bool		NaturalEnabled;
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
	public:
		Config(std::string filename);

		// Logging is always enabled, this enables in-game ui logging.
		bool						LoggingEnabled;

		// Toggles for base game effects.
		FXConfig					FX;
		// Toggles for additional immersive mod features.
		ImmersionConfig				Immersion;

		// Feature specific configs.

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
	};
}
