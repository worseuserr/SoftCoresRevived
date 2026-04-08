#pragma once
#include "SoftCores/Mod/Mod.h"
#include "SoftCores/Util/Event.h"

namespace SoftCores
{
	class	FXOverride : public Feature
	{
		Util::Connection<void *, float>	*TickConnection = nullptr;

	public:
		FXOverride(ModContext *context);
		void	Tick(void *_, float dTime) const;
		void	Initialize() override;
	};
}
