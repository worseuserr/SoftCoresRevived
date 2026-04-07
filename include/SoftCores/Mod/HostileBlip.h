#pragma once
#include "Mod.h"
#include "SoftCores/Util/Event.h"
#include <map>
#include "Sdk/types.h"

namespace SoftCores
{
	enum class	BlipState
	{
		Visible,
		Invisible,
		Disabled,
	};

	class	HostileBlip : public Feature
	{
		Util::Connection<void *, float>	*TickConnection;
		// Counters for HasDurationPassed in ProcessBlip().
		unsigned long long				Counter = 0;
		unsigned long long				CleanupCounter = 0;
		std::map<Ped, BlipState>		VisiblityMap; // Store ped by their visiblity (instance member)

	public:
		HostileBlip(ModContext *context);
		void		Initialize() override;
		void		Tick(void *_, float dTime);
		void		ProcessBlip(Ped ped, Ped playerPed, Ped horsePed, bool isInAHostileScenario);
		void		CleanupMap(Ped *pedArr, int pedCount);

		static BlipState	BoolToState(bool b);
		static BlipState	NegateState(BlipState state);
	};
}
