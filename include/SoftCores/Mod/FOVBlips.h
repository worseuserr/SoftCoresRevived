#pragma once
#include "Mod.h"
#include "SoftCores/Util/Event.h"
#include <map>
#include "Sdk/types.h"

namespace SoftCores
{
	class	FOVBlips : public Feature
	{
		Util::Connection<void *, float>	*TickConnection = nullptr;

	public:
		FOVBlips(ModContext *context);
		void		Initialize() override;
		void		Tick(void *_, float dTime);
		void		ProcessBlip(Ped ped);
	};
}
