#pragma once
#include "SoftCores/Mod/Mod.h"
#include "SoftCores/Util/Event.h"

namespace SoftCores
{
	class	FXOverride : public Feature
	{
		Util::Connection<Util::NO_SENDER, float>	*TickConnection = nullptr;

	public:
		explicit	FXOverride(ModContext *context)
			: Feature(context) {}
		void		Tick(Util::NO_SENDER _, float dTime) const;
		void		Initialize() override;
	};
}
