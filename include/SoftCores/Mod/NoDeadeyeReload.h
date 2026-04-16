#pragma once
#include "Mod.h"

namespace SoftCores
{
	class	NoDeadeyeReload : public Feature
	{
	public:
		explicit	NoDeadeyeReload(ModContext *context)
			: Feature(context) {}
		void		Initialize() override;
	};
}
