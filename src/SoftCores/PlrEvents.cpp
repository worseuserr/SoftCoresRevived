#include "SoftCores/PlrEvents.h"

#include "SoftCores/Plr.h"

using namespace SoftCores;

void PlrEvents::FTick(Util::NO_SENDER _, float dTime)
{
	OnSleepingChanged.Update(this, Plr::IsInSleepScenario());
	OnInControlChanged.Update(this, Plr::IsInControl());
	OnDeadeyeCoreChanged.Update(this, Plr::GetCore(Core::Deadeye));
}

PlrEvents::PlrEvents(SoftCores::Tick *tick)
	: OnSleepingChanged(false), OnInControlChanged(false), OnDeadeyeCoreChanged(0)
{
	Tick = tick;
	Tick->OnTick += [this](Util::NO_SENDER _, const float dTime) { FTick(_, dTime); };
}
