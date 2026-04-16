#pragma once

#include "Mod.h"
#include "SoftCores/Util/Event.h"
#include "Sdk/types.h"

namespace SoftCores
{
	class	FOVBlips : public Feature
	{
		Util::Connection<Util::NO_SENDER, float>	*TickConnection = nullptr;

	public:
		explicit	FOVBlips(ModContext *context)
			: Feature(context) {}
		void		Initialize() override;
		void		Tick(Util::NO_SENDER _, float dTime);
		void		ProcessBlip(Ped ped);
	};
}
