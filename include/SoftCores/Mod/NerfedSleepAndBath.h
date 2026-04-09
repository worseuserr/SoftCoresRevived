#pragma once
#include "Mod.h"

namespace SoftCores
{
	class	NerfedSleepAndBath : public Feature
	{
		float	LastDeadeye;
		float	LastHealth;
		bool	HasControl;
		bool	HasRefilledDeadeye;

	public:
		NerfedSleepAndBath(ModContext *context);
		void	Initialize() override;
		void	OnControlChanged(Util::NO_SENDER _, bool isInControl);
		void	OnSleepingChanged(Util::NO_SENDER _, bool isSleeping);
		void	OnDeadeyeChanged(Util::NO_SENDER _, int value);
		void	ResetCores();
	};
}
