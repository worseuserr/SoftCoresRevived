#include "world.h"
#include <keys.h>
#include <natives.h>

using namespace SoftCores;

float	World::IsRaining()
{
	return (MISC::GET_RAIN_LEVEL() > 0.0f);
}

float	World::IsSnowing()
{
	return (MISC::GET_SNOW_LEVEL() > 0.0f);
}

void	World::SetAIDamageModifier(float melee, float weapon)
{
	PED::SET_AI_MELEE_WEAPON_DAMAGE_MODIFIER(melee);
	PED::SET_AI_WEAPON_DAMAGE_MODIFIER(weapon);
}

bool	World::IsPedFriendly(Ped ped)
{
	for (Keys::Key key : Keys::FriendlyPeds)
	{
		if (PED::IS_PED_MODEL(ped, key.Hash()))
			return (true);
	}
	return (false);
}

bool	World::IsStoryFXPlaying()
{
	for (Keys::Key key : Keys::StoryPostFXs)
	{
		if (GRAPHICS::ANIMPOSTFX_IS_RUNNING(key.ToCString()))
			return (true);
	}
	return (false);
}

int		World::GetGameTimer()
{
	return (MISC::GET_GAME_TIMER());
}
