#include "temperature.h"
#include <natives.h>
#include "mathutil.h"

using namespace SoftCores;

float Temp::GetTimeOfDayModifier()
{
	if (CLOCK::GET_CLOCK_HOURS() >= 5 && CLOCK::GET_CLOCK_HOURS() < 11)
		return 1.5f;
	else if (CLOCK::GET_CLOCK_HOURS() >= 11 && CLOCK::GET_CLOCK_HOURS() < 14)
		return 1.25f;
	else if (CLOCK::GET_CLOCK_HOURS() >= 14 && CLOCK::GET_CLOCK_HOURS() < 18)
		return 1.75f;
	else if (CLOCK::GET_CLOCK_HOURS() >= 18 && CLOCK::GET_CLOCK_HOURS() < 23)
		return 2.0f;
	else if (CLOCK::GET_CLOCK_HOURS() >= 23 && CLOCK::GET_CLOCK_HOURS() < 5)
		return 2.5f;
	else return 0.0f;
}

// arbitrary values for temperature points needed for player clothing to match
float Temp::GetClothingTemperaturePointsRequired(Plr plr)
{
	float temperaturePoints[] = { -20.0f, -16.0f, -12.0f, -8.0f, -4.0f, 0.0f, 4.0f, 8.0f, 12.0f, 16.0f, 20.0f, 24.0f, 28.0f }; // based on a climate/temperature map by hopper on reddit https://i.redd.it/p6f6etiw7by11.jpg in celcius
	int size = sizeof(temperaturePoints) / sizeof(temperaturePoints[0]);
	float temp;

	if (!MISC::_SHOULD_USE_METRIC_TEMPERATURE())
	{
		for (int i = 0; i < size; i++)
		{
			temperaturePoints[i] = Math::CelciusToFarenheit(temperaturePoints[i]);
		}
	}

	temp = plr.GetSurroundingTemperature();
	if (plr.GetSurroundingTemperature() < temperaturePoints[0]) // coldest
		return 9.0f;
	else if (temp >= temperaturePoints[0] && temp < temperaturePoints[1])
		return 8.5f;
	else if (temp >= temperaturePoints[1] && temp < temperaturePoints[2])
		return 8.0f;
	else if (temp >= temperaturePoints[2] && temp < temperaturePoints[3])
		return 7.5f;
	else if (temp >= temperaturePoints[3] && temp < temperaturePoints[4])
		return 7.0f;
	else if (temp >= temperaturePoints[4] && temp < temperaturePoints[5])
		return 6.5f;
	else if (temp >= temperaturePoints[5] && temp < temperaturePoints[6])
		return 6.0f;
	else if (temp >= temperaturePoints[6] && temp < temperaturePoints[7])
		return 5.5f;
	else if (temp >= temperaturePoints[7] && temp < temperaturePoints[8])
		return 5.0f;
	else if (temp >= temperaturePoints[8] && temp < temperaturePoints[9])
		return 4.5f;
	else if (temp >= temperaturePoints[9] && temp < temperaturePoints[10])
		return 4.0f;
	else if (temp >= temperaturePoints[10] && temp < temperaturePoints[11])
		return 3.5f;
	else if (temp >= temperaturePoints[11] && temp < temperaturePoints[12])
		return 3.0f;
	else if (temp >= temperaturePoints[12]) // hottest
		return 2.5f;
	else return 0.0f;
}

