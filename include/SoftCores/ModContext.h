#pragma once

#include "Config.h"
#include "PlrEvents.h"
#include "Util/Logger.h"

namespace SoftCores
{
	struct ModContext
	{
		Util::Logger	*Logger;
		Config			*Config;
		PlrEvents		*PlrEvents;
	};
}
