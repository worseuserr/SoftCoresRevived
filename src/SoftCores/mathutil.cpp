#include "mathutil.h"
#include "natives.h"

using namespace SoftCores;


int Math::Round(float x)
{
	return (BUILTIN::ROUND(x));
}

int Math::Ceil(float x)
{
	return (BUILTIN::CEIL(x));
}

int Math::Floor(float x)
{
	return (BUILTIN::FLOOR(x));
}

float Math::ToFloat(int x)
{
	return (BUILTIN::TO_FLOAT(x));
}

float Math::CelciusToFarenheit(float temperature)
{
	return ((temperature * 1.8f) + 32.0f);
}
