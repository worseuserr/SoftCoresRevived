#include "SoftCores/Mod/Mod.h"
#include "SoftCores/Mod/FXOverride.h"
#include "SoftCores/Mod/FOVBlips.h"
#include "SoftCores/Mod/NerfedSleepAndBath.h"

using namespace SoftCores;

Mod::Mod(ModContext *context)
{
	Context = context;

	// All features must be added manually to this list.
	LoadFeature<FXOverride>();
	LoadFeature<FOVBlips>();
	LoadFeature<NerfedSleepAndBath>();
}
