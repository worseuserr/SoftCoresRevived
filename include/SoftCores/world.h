#pragma once
#include <Sdk/types.h>

namespace SoftCores::World
{
	float	IsRaining();
	float	IsSnowing();
	void	SetAIDamageModifier(float melee, float weapon);
	bool	IsPedFriendly(Ped ped);
	bool	IsStoryFXPlaying();
	int		GetGameTimer();
}
