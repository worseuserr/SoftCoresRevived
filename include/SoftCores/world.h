#pragma once
#include <types.h>

namespace SoftCores
{
	namespace World
	{
		float	IsRaining();
		float	IsSnowing();
		void	SetAIDamageModifier(float melee, float weapon);
		bool	IsPedFriendly(Ped ped);
		bool	IsStoryFXPlaying();
		int		GetGameTimer();
	}
}
