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
		void		OnControlChanged(PlrEvents *plrEvents, bool isInControl);
		void		OnBathingChanged(PlrEvents *plrEvents, bool isBathing);
		void		OnMovingChanged(PlrEvents *plrEvents, bool isMoving);
		void		OnSleepingChanged(PlrEvents *plrEvents, bool isSleeping);
		void		OnDeadeyeChanged(PlrEvents *plrEvents, int value);
		void		OnStaminaChanged(PlrEvents *plrEvents, int value);
		void		ResetSleepCores();
		void		ResetBathCores();
	};
}
