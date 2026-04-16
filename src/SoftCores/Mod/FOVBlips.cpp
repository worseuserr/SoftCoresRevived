#include "SoftCores/Mod/FOVBlips.h"

#include "Debug.h"
#include "Sdk/natives.h"
#include "Sdk/types.h"
#include "SoftCores/Keys.h"
#include "SoftCores/Plr.h"
#include "SoftCores/Tick.h"
#include "SoftCores/World.h"

using namespace SoftCores;

// Seems to not work properly while wanted and on some enemies.
void FOVBlips::ProcessBlip(const Ped ped)
{
	static const Hash	MODIFIER_VISIBLE = Keys::GetHash("BLIP_MODIFIER_FADE_IN");
	static const Hash	MODIFIER_NOT_VISIBLE = Keys::GetHash("BLIP_MODIFIER_FADE");
	static const Hash	STYLE_VISIBLE = Keys::GetHash("BLIP_MODIFIER_FADE");
	static const Hash	STYLE_NOT_VISIBLE = Keys::GetHash("BLIP_MODIFIER_FADE_OUT_SLOW");
	Blip	pedBlip;
	bool	isVisible;
	Ped		pedIndex;

	// GET_PED_INDEX_FROM_ENTITY_INDEX is required or the feature won't work. Have no fucking idea why.
	pedIndex = ENTITY::GET_PED_INDEX_FROM_ENTITY_INDEX(ped);
	PED::REQUEST_PED_VISIBILITY_TRACKING(pedIndex);
	isVisible = PED::IS_TRACKED_PED_VISIBLE(pedIndex);
	pedBlip = MAP::GET_BLIP_FROM_ENTITY(ped);
	// These have to be called every time, as tracking the ped's blip state in the script will lose sync with the game.
	MAP::_BLIP_SET_MODIFIER(pedBlip, isVisible ? MODIFIER_VISIBLE : MODIFIER_NOT_VISIBLE);
	MAP::_SET_BLIP_FLASH_STYLE(pedBlip, isVisible ? STYLE_VISIBLE : STYLE_NOT_VISIBLE);
	// For any future devs:
	//   I could not find a definition for _SET_BLIP_FLASH_STYLE in any NativeDB anywhere, in any dataset. Nor any documentation.
	//   I only found a random text file in a repository with it and its associated address.
	//   I'm still not sure what it exactly does, but this feature doesn't work properly without it.
	//   If you can't find a natives header with it, the address is 0xB059D7BD3D78C16F. You're welcome.
}

void FOVBlips::Tick(Util::NO_SENDER _, float dTime)
{
	const ImmersionConfig	&config = Context->Config->Immersion;
	Ped	pedArr[1024]{}; // Initialize at 1024, only index upto Config->PedRange
	Ped	playerPed;
	Ped	horsePed;
	int	pedCount;
	int	i;

	if (!config.HideOutOfViewBlips)// || !HasDurationPassed(LogicInterval, &Counter)) // Have to run every frame otherwise some blips still show.
		return ;
	if (!config.HideOutOfViewBlipsInMissions && Plr::IsInMission())
		return ;
	pedCount = World::GetAllPeds(pedArr, Context->Config->PedRange);
	playerPed = PLAYER::PLAYER_PED_ID();
	horsePed = PLAYER::_GET_SADDLE_HORSE_FOR_PLAYER(PLAYER::PLAYER_ID());
	for (i = 0; i < pedCount; i++)
	{
		if (pedArr[i] == playerPed || pedArr[i] == horsePed)// || World::IsPedFriendly(pedArr[i])) // Problematic.
			continue ;
		if (config.HideOutOfViewBlipsOnlyHostile && !Plr::IsPedHostileAndNearby(pedArr[i], 100.0f))
			continue ;
		if (!config.HideOutOfViewBlipsForCorpses && PED::IS_PED_DEAD_OR_DYING(pedArr[i], true))
			continue ;
		ProcessBlip(pedArr[i]);
	}
}


void FOVBlips::Initialize()
{
	Debug::Log(LogLevel::Info, "FOVBlips initialized");
	Debug::Log(LogLevel::Debug, "FOVBlips config:");
	Debug::Log(LogLevel::Debug, "   HideOutOfViewBlips: {}", Context->Config->Immersion.HideOutOfViewBlips);
	Debug::Log(LogLevel::Debug, "   HideOutOfViewBlipsInMissions: {}", Context->Config->Immersion.HideOutOfViewBlipsInMissions);
	Debug::Log(LogLevel::Debug, "   HideOutOfViewBlipsOnlyHostile: {}", Context->Config->Immersion.HideOutOfViewBlipsOnlyHostile);
	TickConnection = Context->Tick->OnTick += [this](Util::NO_SENDER _, const float dTime){ Tick(_, dTime); };
}
