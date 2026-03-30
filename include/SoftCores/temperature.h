#pragma once
#include <SoftCores/Plr.h>

// Temperature functions.
namespace SoftCores::Temp
{
	float GetTimeOfDayModifier();
	float GetClothingTemperaturePointsRequired(Plr plr);
	// arbitrary values for temperature points needed for player clothing to match
}
