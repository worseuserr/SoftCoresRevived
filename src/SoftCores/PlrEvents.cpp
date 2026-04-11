#include "SoftCores/PlrEvents.h"

#include "SoftCores/Plr.h"

using namespace SoftCores;

void PlrEvents::FTick(Util::NO_SENDER _, float dTime)
{
	OnSleepingChanged.Update(this, Plr::IsInSleepScenario());
	OnControlChanged.Update(this, Plr::IsInControl());
	OnBathingChanged.Update(this, Plr::IsBathing());
	OnMovingChanged.Update(this, Plr::IsMoving());
	OnDeadeyeCoreChanged.Update(this, Plr::GetCore(Core::Deadeye));
	OnStaminaCoreChanged.Update(this, Plr::GetCore(Core::Stamina));
}

PlrEvents::PlrEvents(SoftCores::Tick *tick)
	: OnSleepingChanged(false), OnControlChanged(false), OnMovingChanged(false), OnBathingChanged(false),
	OnDeadeyeCoreChanged(0), OnStaminaCoreChanged(0)
{
	Tick = tick;
	Tick->OnTick += [this](Util::NO_SENDER _, const float dTime) { FTick(_, dTime); };
}
