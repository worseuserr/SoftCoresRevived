#pragma once
#include <Sdk/types.h>

namespace SoftCores::World
{
	bool	IsRaining();
	bool	IsSnowing();
	void	SetAIDamageModifier(float melee, float weapon);
	bool	IsPedFriendly(Ped ped);
	bool	IsStoryFXPlaying();
	int		GetGameTimer();
	int		GetAllPeds(int *arr, int arrSize);
}
