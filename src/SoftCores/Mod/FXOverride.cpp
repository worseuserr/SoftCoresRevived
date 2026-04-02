#include "SoftCores/Mod/FXOverride.h"

using namespace SoftCores;

FXOverride::FXOverride(Util::Logger *logger, SoftCores::Config *config)
	: Feature(logger, config) {}

void FXOverride::Initialize()
{
	if (!Config->FX.Enabled)
		return ;

}
