#include "SoftCores/Mod/Mod.h"

using namespace SoftCores;

Feature::Feature(ModContext *context)
{
	Context = context;
}

void Feature::Initialize()
{
	Context->Logger->Write("Feature without initialize.");
}
