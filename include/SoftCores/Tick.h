#pragma once

#include <SoftCores/Util/Event.h>

using namespace SoftCores::Util;

namespace SoftCores
{
	class	Tick
	{
	private:
		static bool	LoopActive;
		static void	Loop();
	public:
		// value: deltaTime
		static Event<Tick, float>	OnTick;
		static void					StartLoop();
		static void					StopLoop();
	};
}
