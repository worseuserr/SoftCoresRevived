#pragma once
#include <plr.h>

namespace SoftCores
{
	// Temperature.
	namespace Temp
	{
		float GetTimeOfDayModifier();
		float GetClothingTemperaturePointsRequired(Plr plr);
		// arbitrary values for temperature points needed for player clothing to match
	}
}