#pragma once

#include "Mod.h"

namespace SoftCores
{
	class	NerfedSleepAndBath : public Feature
	{
		float	LastDeadeye = 0.0f;
		float	LastHealth = 0.0f;
		float	LastStamina = 0.0f;
		bool	HasControl = false;
		bool	HasRefilledDeadeye = false;
		bool	IsBathing = false;

	public:
		explicit	NerfedSleepAndBath(ModContext *context)
			: Feature(context) {}
		void		Initialize() override;
		void		OnControlChanged(Util::NO_SENDER _, bool isInControl);
		void		OnBathingChanged(Util::NO_SENDER _, bool isBathing);
		void		OnMovingChanged(Util::NO_SENDER _, bool isMoving);
		void		OnSleepingChanged(Util::NO_SENDER _, bool isSleeping);
		void		OnDeadeyeChanged(Util::NO_SENDER _, int value);
		void		OnStaminaChanged(Util::NO_SENDER _, int value);
		void		ResetSleepCores();
		void		ResetBathCores();
	};
}
