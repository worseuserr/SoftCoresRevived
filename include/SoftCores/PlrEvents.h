#pragma once

#include "Tick.h"
#include "Util/Event.h"

namespace SoftCores
{
	class	PlrEvents
	{
		Tick	*Tick;

	public:
		Util::ChangedEvent<PlrEvents, bool>	OnSleepingChanged;
		Util::ChangedEvent<PlrEvents, bool>	OnControlChanged;
		Util::ChangedEvent<PlrEvents, bool>	OnMovingChanged;
		Util::ChangedEvent<PlrEvents, bool>	OnBathingChanged;
		Util::ChangedEvent<PlrEvents, int>	OnDeadeyeCoreChanged;
		Util::ChangedEvent<PlrEvents, int>	OnStaminaCoreChanged;

		PlrEvents(SoftCores::Tick *tick);
		void FTick(Util::NO_SENDER _, float dTime);
	};


}
