#pragma once

#include "Plr.h"
#include "Tick.h"
#include "Util/Event.h"

namespace SoftCores
{
	class	PlrEvents
	{
		Tick	*Tick;

	public:
		Util::ChangedEvent<PlrEvents, bool>	OnSleepingChanged = false;
		Util::ChangedEvent<PlrEvents, bool>	OnControlChanged = false;
		Util::ChangedEvent<PlrEvents, bool>	OnMovingChanged = false;
		Util::ChangedEvent<PlrEvents, bool>	OnBathingChanged = false;
		Util::ChangedEvent<PlrEvents, bool>	OnDeadeyeChanged = false;
		Util::ChangedEvent<PlrEvents, int>	OnDeadeyeCoreChanged = 0;
		Util::ChangedEvent<PlrEvents, int>	OnStaminaCoreChanged = 0;

		void FTick(Util::NO_SENDER _, const float dTime)
		{
			OnSleepingChanged.Update(this, Plr::IsInSleepScenario());
			OnControlChanged.Update(this, Plr::IsInControl());
			OnBathingChanged.Update(this, Plr::IsBathing());
			OnMovingChanged.Update(this, Plr::IsMoving());
			OnDeadeyeChanged.Update(this, Plr::IsDeadeyeActivated());
			OnDeadeyeCoreChanged.Update(this, Plr::GetCore(Core::Deadeye));
			OnStaminaCoreChanged.Update(this, Plr::GetCore(Core::Stamina));
		}

		PlrEvents(SoftCores::Tick *tick)
		{
				Tick = tick;
				Tick->OnTick += [this](Util::NO_SENDER _, const float dTime) { FTick(_, dTime); };
		}
	};
}
