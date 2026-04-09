#pragma once

#include "Config.h"
#include "PlrEvents.h"
#include "Tick.h"
#include "Util/Logger.h"

namespace SoftCores
{
	struct ModContext
	{
		Util::Logger	*Logger;
		Config			*Config;
		PlrEvents		*PlrEvents;
		Tick			*Tick;
	};
}
