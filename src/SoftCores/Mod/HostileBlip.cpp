#include "SoftCores/Mod/HostileBlip.h"
#include "Keyboard.h"
#include "Sdk/natives.h"
#include "Sdk/types.h"
#include "SoftCores/Keys.h"
#include "SoftCores/Plr.h"
#include "SoftCores/Tick.h"
#include "SoftCores/World.h"
#include "SoftCores/Util/Time.h"

using namespace SoftCores;

HostileBlip::HostileBlip(Util::Logger *logger, SoftCores::Config *config)
	: Feature(logger, config), TickConnection(nullptr) {}

// Note: Regardless of what your compiler tells you, do NOT define Ped or any native types as const. It causes headaches.
void ProcessBlip(Ped &ped, Ped &playerPed, Ped &horsePed, const bool &isInAHostileScenario)
{
	Blip	pedBlip;
	bool	isPedVisible;

	if (!Plr::IsPedHostileAndNearby(ped) && !isInAHostileScenario)
		return ;
	if (ped != playerPed
		&& ped != horsePed
		&& !World::IsPedFriendly(ped)
		&& ENTITY::IS_ENTITY_A_PED(ped)
		&& !PED::IS_PED_DEAD_OR_DYING(ped, true))
	{
		PED::REQUEST_PED_VISIBILITY_TRACKING(ped);
		pedBlip = MAP::GET_BLIP_FROM_ENTITY(ped);
		isPedVisible = PED::IS_TRACKED_PED_VISIBLE(ped);
		MAP::_BLIP_SET_MODIFIER(pedBlip, Keys::GetHash(isPedVisible ? "BLIP_MODIFIER_FADE_IN" : "BLIP_MODIFIER_FADE"));
		MAP::_SET_BLIP_FLASH_STYLE(pedBlip, Keys::GetHash(isPedVisible ? "BLIP_MODIFIER_FADE" : "BLIP_MODIFIER_FADE_OUT_SLOW"));
		// For any future devs:
		//   I could not find a definition for _SET_BLIP_FLASH_STYLE in any NativeDB anywhere, in any dataset. Nor any documentation.
		//   I'm still not sure what it exactly does, but this feature doesn't work properly without it.
		//   If you can't find a natives header with it, the address is 0xB059D7BD3D78C16F. You're welcome.
	}
}

// Actual logic only runs every 100 ms. This reduces jitteriness of blips and improves performance.
void HostileBlip::Tick(void *_, float dTime) const
{
	Ped                			pedArr[1024]; // Initialize at 1024, only index upto Config->PedRange
	Ped                			playerPed;
	Ped                			horsePed;
	bool               			isInAHostileScenario;
	int                			i;
	static unsigned long long	counter = 0;
	// Should consider moving logic, variable list is too large.

	if (Plr::IsInMission() && !Config->Immersion.HideHostileBlipsInMissions)
		return ;
	if (!HasDurationPassed(100, &counter)) // Only run logic every 100ms.
		return ;
	isInAHostileScenario = Plr::IsInCombat() || Plr::IsPursued() || Plr::IsInMission(); // From original mod, I'm unsure if this is actually needed.
	playerPed = PLAYER::PLAYER_PED_ID();
	horsePed = PLAYER::_GET_SADDLE_HORSE_FOR_PLAYER(PLAYER::PLAYER_ID());
	for (i = 0; i < World::GetAllPeds(pedArr, Config->PedRange); i++)
		ProcessBlip(pedArr[i], playerPed, horsePed, isInAHostileScenario);
}


void HostileBlip::Initialize()
{
	if (!Config->Immersion.HideHostileBlips)
		return ;
	TickConnection = Tick::OnTick += [this](void *_, float dTime){ Tick(_, dTime); };
}
