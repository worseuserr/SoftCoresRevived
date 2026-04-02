#include "SoftCores/Mod/Mod.h"

using namespace SoftCores;

Feature::Feature(Util::Logger *logger, SoftCores::Config *config)
{
	Logger = logger;
	Config = config;
}

void Feature::Initialize()
{
	Logger->Write("Feature without initialize.");
}
