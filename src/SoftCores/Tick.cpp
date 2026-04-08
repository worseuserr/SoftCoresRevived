#include "SoftCores/Tick.h"
#include "Sdk/main.h"

using namespace SoftCores;

void	Tick::Loop()
{
	while (LoopActive)
	{
		OnTick.Dispatch(nullptr, 0.0f);
		WAIT(0);
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
