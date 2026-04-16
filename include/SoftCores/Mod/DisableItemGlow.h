#pragma once

#include "Mod.h"

namespace SoftCores
{
	// Single feature class for both DisableWeaponGlow and DisablePickupGlow.
	class	DisableItemGlow : public Feature
	{
		unsigned long long	Counter = 0;

	public:
		unsigned long long	Interval = 250;

		explicit	DisableItemGlow(ModContext *context)
			: Feature(context) {}
		void	Initialize() override;
		void	OnTick(Util::NO_SENDER _, float dTime);
	};
}
