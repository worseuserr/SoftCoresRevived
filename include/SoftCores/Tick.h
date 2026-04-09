#pragma once

#include <SoftCores/Util/Event.h>

namespace SoftCores
{
	class	Tick
	{
		bool	LoopActive = false;
		void	Loop();

	public:
		// value: deltaTime
		Util::Event<Util::NO_SENDER, float>	OnTick;
		void								StartLoop();
		void								StopLoop();
	};
}
