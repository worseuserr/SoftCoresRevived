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

using namespace SoftCores;

HostileBlip::HostileBlip(ModContext *context)
	: Feature(context), TickConnection(nullptr) {}

void CleanupMap(Ped *pedArr, int pedCount, std::map<Ped, bool> &visiblityMap)
{
	std::unordered_set	pedSet(pedArr, pedArr + pedCount);
	pedSet.reserve(pedCount);
	std::erase_if(visiblityMap, [&pedSet](const std::pair<Ped, bool>& pair) {
		return (!pedSet.contains(pair.first));
	});
}

// Note: Regardless of what your compiler tells you, do NOT define Ped or any native types as const. It causes headaches.
void ProcessBlip(Ped ped, Ped playerPed, Ped horsePed, const bool isInAHostileScenario, std::map<Ped, bool>	&VisiblityMap)
{
	static const Hash	ModifierVisible = Keys::GetHash("BLIP_MODIFIER_FADE_IN");
	static const Hash	ModifierNotVisible = Keys::GetHash("BLIP_MODIFIER_FADE");
	static const Hash	StyleVisible = Keys::GetHash("BLIP_MODIFIER_FADE");
	static const Hash	StyleNotVisible = Keys::GetHash("BLIP_MODIFIER_FADE_OUT_SLOW");
	Blip				pedBlip;
	bool				isPedVisible;

	if (ped == playerPed || ped == horsePed)
		return ;
	if (!isInAHostileScenario && !Plr::IsPedHostileAndNearby(ped))
		return ;
	if (World::IsPedFriendly(ped) || PED::IS_PED_DEAD_OR_DYING(ped, true))
		// && ENTITY::IS_ENTITY_A_PED(ped) // From original mod, seems redundant.
		return ;
	PED::REQUEST_PED_VISIBILITY_TRACKING(ped); // This may be moved into the condition below if tracking persists internally.
	isPedVisible = PED::IS_TRACKED_PED_VISIBLE(ped);
	if (!VisiblityMap.contains(ped))
		VisiblityMap[ped] = isPedVisible;
	else if (VisiblityMap[ped] == isPedVisible)
		return ;
	pedBlip = MAP::GET_BLIP_FROM_ENTITY(ped);
	MAP::_BLIP_SET_MODIFIER(pedBlip, isPedVisible ? ModifierVisible : ModifierNotVisible);
	MAP::_SET_BLIP_FLASH_STYLE(pedBlip, isPedVisible ? StyleVisible : StyleNotVisible);
	VisiblityMap[ped] = isPedVisible;
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
	isInAHostileScenario = Plr::IsInCombat() || Plr::IsPursued() || Plr::IsInMission(); // From original mod, I'm unsure if this is actually needed.
	playerPed = PLAYER::PLAYER_PED_ID();
	horsePed = PLAYER::_GET_SADDLE_HORSE_FOR_PLAYER(PLAYER::PLAYER_ID());
	if (HasDurationPassed(5000, &CleanupCounter))
		CleanupMap(pedArr, pedCount, VisiblityMap);
	for (i = 0; i < pedCount; i++)
		ProcessBlip(pedArr[i], playerPed, horsePed, isInAHostileScenario, VisiblityMap);
}


void HostileBlip::Initialize()
{
	Context->Logger->Write("HostileBlip initialized");
	TickConnection = Tick::OnTick += [this](void *_, float dTime){ Tick(_, dTime); };
}
