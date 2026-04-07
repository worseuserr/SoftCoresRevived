#include "SoftCores/Mod/HostileBlip.h"
#include "Sdk/natives.h"
#include "Sdk/types.h"
#include "SoftCores/Keys.h"
#include "SoftCores/Plr.h"
#include "SoftCores/Tick.h"
#include "SoftCores/World.h"
#include "SoftCores/Util/Time.h"
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <format>

using namespace SoftCores;

HostileBlip::HostileBlip(ModContext *context)
	: Feature(context), TickConnection(nullptr) {}

void HostileBlip::CleanupMap(Ped *pedArr, const int pedCount)
{
	std::unordered_set	pedSet(pedArr, pedArr + pedCount);
	pedSet.reserve(pedCount);
	std::erase_if(VisiblityMap, [&pedSet](const std::pair<Ped, BlipState>& pair) {
		return (!pedSet.contains(pair.first));
	});
}

BlipState HostileBlip::BoolToState(const bool b)
{
	return (b ? BlipState::Visible : BlipState::Invisible);
}

BlipState HostileBlip::NegateState(const BlipState state)
{
	return (state == BlipState::Invisible ? BlipState::Visible : BlipState::Invisible);
}

void HostileBlip::ProcessBlip(const Ped ped, const Ped playerPed, const Ped horsePed, const bool isInAHostileScenario)
{
	static const Hash	ModifierVisible = Keys::GetHash("BLIP_MODIFIER_FADE_IN");
	static const Hash	ModifierNotVisible = Keys::GetHash("BLIP_MODIFIER_FADE");
	static const Hash	StyleVisible = Keys::GetHash("BLIP_MODIFIER_FADE");
	static const Hash	StyleNotVisible = Keys::GetHash("BLIP_MODIFIER_FADE_OUT_SLOW");
	Blip		pedBlip;
	BlipState	blipState;

	if (ped == playerPed || ped == horsePed)
		return ;
	if (VisiblityMap.contains(ped) && (VisiblityMap[ped] == BlipState::Disabled))
		return ;
	if (!isInAHostileScenario && !Plr::IsPedHostileAndNearby(ped, 500.0f))
		return ;
	if (World::IsPedFriendly(ped))
		// && ENTITY::IS_ENTITY_A_PED(ped) // From original mod, seems redundant.
			return ;
	PED::REQUEST_PED_VISIBILITY_TRACKING(ped);
	blipState = BoolToState(PED::IS_TRACKED_PED_VISIBLE(ped));
	if (!VisiblityMap.contains(ped))
	{
		// Force blip to update by causing VisiblityMap[ped] != blipState.
		// The states HAVE to start as Visible to Invisible, otherwise the engine doesn't update the blips.
		VisiblityMap[ped] = BlipState::Visible;
		blipState = BlipState::Invisible;
	}
	else if (VisiblityMap[ped] == blipState)
		return ;
	if (PED::IS_PED_DEAD_OR_DYING(ped, true))
	{
		// Set temp state to invisible to fade out.
		blipState = BlipState::Invisible;
		VisiblityMap[ped] = BlipState::Disabled;
	}
	else
		VisiblityMap[ped] = blipState;
	pedBlip = MAP::GET_BLIP_FROM_ENTITY(ped);
	MAP::_BLIP_SET_MODIFIER(pedBlip, (blipState == BlipState::Visible) ? ModifierVisible : ModifierNotVisible);
	MAP::_SET_BLIP_FLASH_STYLE(pedBlip, (blipState == BlipState::Visible) ? StyleVisible : StyleNotVisible);
	// For any future devs:
	//   I could not find a definition for _SET_BLIP_FLASH_STYLE in any NativeDB anywhere, in any dataset. Nor any documentation.
	//   I only found a random text file in a repository with it and its associated address.
	//   I'm still not sure what it exactly does, but this feature doesn't work properly without it.
	//   If you can't find a natives header with it, the address is 0xB059D7BD3D78C16F. You're welcome.
}

// Actual logic only runs every 100 ms. This reduces jitteriness of blips and improves performance.
void HostileBlip::Tick(void *_, float dTime)
{
	Ped		pedArr[1024]{}; // Initialize at 1024, only index upto Config->PedRange
	Ped		playerPed;
	Ped		horsePed;
	bool	isInAHostileScenario;
	int		pedCount;
	int		i;
	// Feature seems to not work for some enemies. Needs investigation.

	if (!Context->Config->Immersion.HideHostileBlips || !HasDurationPassed(100, &Counter)) // Only run logic every 100ms.
		return ;
	if (Plr::IsInMission() && !Context->Config->Immersion.HideHostileBlipsInMissions)
		return ;
	pedCount = World::GetAllPeds(pedArr, Context->Config->PedRange);
	isInAHostileScenario = Plr::IsInCombat() || Plr::IsPursued() || Plr::IsInMission(); // Probably needed.
	playerPed = PLAYER::PLAYER_PED_ID();
	horsePed = PLAYER::_GET_SADDLE_HORSE_FOR_PLAYER(PLAYER::PLAYER_ID());
	if (HasDurationPassed(5000, &CleanupCounter))
		CleanupMap(pedArr, pedCount);
	for (i = 0; i < pedCount; i++)
		ProcessBlip(pedArr[i], playerPed, horsePed, isInAHostileScenario);
}


void HostileBlip::Initialize()
{
	Context->Logger->Write("HostileBlip initialized");
	TickConnection = Tick::OnTick += [this](void *_, float dTime){ Tick(_, dTime); };
}
