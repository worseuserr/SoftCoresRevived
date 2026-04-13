#include "Debug.h"
#include "SoftCores/Mod/Mod.h"

using namespace SoftCores;

Feature::Feature(ModContext *context)
{
	Context = context;
}

void Feature::Initialize()
{
	Debug::Log(LogLevel::Warn, "Feature without initialize.");
}
