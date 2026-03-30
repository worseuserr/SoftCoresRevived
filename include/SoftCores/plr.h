#pragma once
#include <SoftCores/Enums.h>

namespace SoftCores
{
	// Superclass containing all necessary player methods
	class Plr
	{
	public:
		int		GetMaxOuterCore(Core core);
		int		GetOuterCore(Core core);
		void	SetOuterCore(Core core, int value);
		int		GetCore(Core core);
		void	SetCore(Core core, int value);
		int		GetHorseCore(Core core);
		void	SetHorseCore(Core core, int value);
		bool	IsCoreOverpowered(Core core);
		bool	IsOuterCoreOverpowered(Core core);
		bool	IsHorseCoreOverpowered(Core core);
		void	SetDamageModifier(float melee, float weapon);
		void	SetHealthRegen(float multiplier);
		void	UnequipClothes(ClothingType type);
		bool	IsWearing(ClothingType type);
		bool	IsAlive();
		bool	IsPlaying();
		bool	IsInMission();
		bool	IsInControl();
		bool	IsPursued();
		bool	IsActiveInScenario();
		bool	IsUsingAnyScenario();
		bool	IsBathing();
		bool	IsInCombat();
		bool	IsPedHostileAndNearby(Ped ped);
		bool	IsIdle();
		bool	IsMounted();
		bool	IsInCover();
		bool	IsDeadeyeActivated();
		bool	IsIndoors();
		bool	IsSubmerged();
		bool	IsMoving();
		bool	IsInCampScenario();
		bool	IsInSleepScenario();
		float	GetClothingTemperaturePoints();
		float	GetSurroundingTemperature();
	};
}
