#pragma once

#include "Mod.h"

namespace SoftCores
{
	class	DisableItemGlow : public Feature
	{
		unsigned long long	Counter = 0;

	public:
		unsigned long long	Interval = 250;

		DisableItemGlow(ModContext *context);
		void	Initialize() override;
		void	OnTick(Util::NO_SENDER _, const float dTime);
	};
}
