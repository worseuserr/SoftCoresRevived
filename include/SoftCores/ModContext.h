#pragma once

#include "Config.h"
#include "PlrEvents.h"
#include "Tick.h"

namespace SoftCores
{
	struct ModContext
	{
		Config			*Config;
		PlrEvents		*PlrEvents;
		Tick			*Tick;
	};
}
