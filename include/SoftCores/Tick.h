#pragma once

#include <SoftCores/Util/Event.h>

using namespace SoftCores::Util;

namespace SoftCores
{
	class	Tick
	{
		static bool	LoopActive;
		static void	Loop();

	public:
		// value: deltaTime
		static Event<NO_SENDER, float>	OnTick;
		static void						StartLoop();
		static void						StopLoop();
	};
}
