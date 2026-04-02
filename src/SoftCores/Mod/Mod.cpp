#include "SoftCores/Mod/Mod.h"
#include "SoftCores/Mod/FXOverride.h"

using namespace SoftCores;

Mod::Mod(Util::Logger *logger, SoftCores::Config *config)
{
	Logger = logger;
	Config = config;

	// All features must be added manually to this list.
	LoadFeature<FXOverride>();
}

Mod::~Mod() {
	for (const Feature *feat : Features)
	{
		delete (feat);
	}
}
