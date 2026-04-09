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
		Util::ChangedEvent<PlrEvents, bool>	OnInControlChanged;
		Util::ChangedEvent<PlrEvents, int>	OnDeadeyeCoreChanged;

		PlrEvents(SoftCores::Tick *tick);
		void FTick(Util::NO_SENDER _, float dTime);
	};


}
