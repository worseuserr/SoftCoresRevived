#pragma once
#include "Mod.h"
#include "SoftCores/Util/Event.h"

namespace SoftCores
{
	class HostileBlip : public Feature
	{
		Util::Connection<void *, float>	*TickConnection;
		// Counter for HasDurationPassed in ProcessBlip().
		unsigned long long				Counter = 0;

	public:
		HostileBlip(Util::Logger *logger, SoftCores::Config *config);
		void	Tick(void *_, float dTime);
		void	Initialize() override;
	};
}
