#pragma once
#include <Sdk/types.h>

namespace SoftCores::Util::Math
{
	int			Round(float x);
	int			Ceil(float x);
	int			Floor(float x);
	float		ToFloat(int x);
	float		CelciusToFarenheit(float temperature);
	int			HealthAsPercentage(Entity entity);
}
