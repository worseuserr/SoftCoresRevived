#include "SoftCores/Tick.h"

using namespace SoftCores;

Event<void*, float>	Tick::OnTick;
bool				Tick::LoopActive;

void	Tick::Loop()
{
	while (LoopActive)
	{
		OnTick.Dispatch(nullptr, 0.0f);
	}
}

void	Tick::StartLoop()
{
	LoopActive = true;
	Loop();
}

void	Tick::StopLoop()
{
	LoopActive = false;
}
