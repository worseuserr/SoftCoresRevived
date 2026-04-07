#pragma once
#include "Mod.h"
#include "SoftCores/Util/Event.h"
#include <map>
#include "Sdk/types.h"

namespace SoftCores
{
	class	HostileBlip : public Feature
	{
		Util::Connection<void *, float>	*TickConnection;
		// Counters for HasDurationPassed in ProcessBlip().
		unsigned long long				Counter = 0;
		unsigned long long				CleanupCounter = 0;
		std::map<Ped, bool>				VisiblityMap; // Store ped by their visiblity (instance member)

	public:
		HostileBlip(ModContext *context);
		void	Tick(void *_, float dTime);
		void	Initialize() override;
	};
}
