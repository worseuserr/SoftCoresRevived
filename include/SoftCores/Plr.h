#pragma once
#include <SoftCores/Enums.h>

namespace SoftCores
{
	// Superclass containing all necessary player methods
	class	Plr
	{
	public:
		static Ped		GetPed();
		static int		GetMaxOuterCore(Core core);
		static int		GetOuterCore(Core core);
		static void		SetOuterCore(Core core, int value);
		static int		GetCore(Core core);
		static void		SetCore(Core core, int value);
		static int		GetHorseCore(Core core);
		static void		SetHorseCore(Core core, int value);
		static bool		IsCoreOverpowered(Core core);
		static bool		IsOuterCoreOverpowered(Core core);
		static bool		IsHorseCoreOverpowered(Core core);
		static void		SetDamageModifier(float melee, float weapon);
		static void		SetHealthRegen(float multiplier);
		static void		UnequipClothes(ClothingType type);
		static bool		IsWearing(ClothingType type);
		static bool		IsAlive();
		static bool		IsPlaying();
		static bool		IsInMission();
		static bool		IsInControl();
		static bool		IsPursued();
		static bool		IsActiveInScenario();
		static bool		IsUsingAnyScenario();
		static bool		IsBathing();
		static bool		IsInCombat();
		static bool		IsPedHostileAndNearby(Ped ped, float distance);
		static bool		IsIdle();
		static bool		IsMounted();
		static bool		IsInCover();
		static bool		IsDeadeyeActivated();
		static bool		IsIndoors();
		static bool		IsSubmerged();
		static bool		IsMoving();
		static bool		IsInCampScenario();
		static bool		IsInSleepScenario();
		static float	GetClothingTemperaturePoints();
		static float	GetSurroundingTemperature();
	};
}
