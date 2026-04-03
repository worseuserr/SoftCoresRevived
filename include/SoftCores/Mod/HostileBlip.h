#pragma once
#include "Mod.h"
#include "SoftCores/Util/Event.h"

namespace SoftCores
{
	class HostileBlip : public Feature
	{
		Util::Connection<void *, float>	*TickConnection;

	public:
		HostileBlip(Util::Logger *logger, SoftCores::Config *config);
		void	Tick(void *_, float dTime) const;
		void	Initialize() override;
	};
}
