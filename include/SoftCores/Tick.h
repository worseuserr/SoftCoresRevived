#pragma once

#include <SoftCores/Util/Event.h>

using namespace SoftCores::Util;

namespace SoftCores
{
	class	Tick
	{
		bool	LoopActive = false;
		void	Loop();

	public:
		// value: deltaTime
		Event<NO_SENDER, float>	OnTick;
		void					StartLoop();
		void					StopLoop();
	};
}
