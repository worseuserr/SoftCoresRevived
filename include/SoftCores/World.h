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
	int		GetAllVehicles(int *arr, int arrSize);
	int		GetAllObjects(int *arr, int arrSize);
	int		GetAllPickups(int *arr, int arrSize);
}
