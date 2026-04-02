#pragma once
#include "SoftCores/Mod/Mod.h"

using namespace SoftCores;

class FXOverride : public Feature
{
public:
	FXOverride(Util::Logger *logger, SoftCores::Config *config);

	void	Initialize() override;
};
