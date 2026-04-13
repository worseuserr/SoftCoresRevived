#include <SoftCores/Util/Math.h>
#include <Sdk/natives.h>

using namespace SoftCores::Util;


int Math::Round(const float x)
{
	return (BUILTIN::ROUND(x));
}

int Math::Ceil(const float x)
{
	return (BUILTIN::CEIL(x));
}

int Math::Floor(const float x)
{
	return (BUILTIN::FLOOR(x));
}

float Math::ToFloat(const int x)
{
	return (BUILTIN::TO_FLOAT(x));
}

float Math::CelciusToFarenheit(const float temperature)
{
	return ((temperature * 1.8f) + 32.0f);
}

int Math::HealthAsPercentage(const Entity entity)
{
	return (Math::Round(ENTITY::GET_ENTITY_HEALTH(entity) * 100.0f / ENTITY::GET_ENTITY_MAX_HEALTH(entity, 0)));
}
