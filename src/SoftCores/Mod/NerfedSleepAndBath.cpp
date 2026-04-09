#include "SoftCores/Mod/NerfedSleepAndBath.h"

#include <format>

#include "Sdk/natives.h"
#include "SoftCores/Keys.h"
#include "SoftCores/Plr.h"

using namespace SoftCores;

NerfedSleepAndBath::NerfedSleepAndBath(ModContext *context)
	: Feature(context) {}

void NerfedSleepAndBath::ResetCores()
{
	Plr::SetCore(Core::Deadeye, LastDeadeye);
	Plr::SetCore(Core::Health, LastHealth);
	HasControl = true;
	HasRefilledDeadeye = false;
}

void NerfedSleepAndBath::OnControlChanged(Util::NO_SENDER _, const bool isInControl)
{
	if (!isInControl)
	{
		LastDeadeye = Plr::GetCore(Core::Deadeye);
		LastHealth = Plr::GetCore(Core::Health);
	}
	HasControl = isInControl;
	HasRefilledDeadeye = false;
}

void NerfedSleepAndBath::OnSleepingChanged(Util::NO_SENDER _, const bool isSleeping)
{
	if (!isSleeping)
		return ;
	if (HasRefilledDeadeye)
		ResetCores();
}

void NerfedSleepAndBath::OnDeadeyeChanged(Util::NO_SENDER _, const int value)
{
	if (HasControl)
		return ;
	// This check is for when the player sets up a tent during rain, which for some reason doesn't set IsSleeping.
	if (PED::_IS_PED_USING_SCENARIO_HASH(Plr::GetPed(), Keys::GetHash("PROP_PLAYER_SLEEP_TENT_A_FRAME")))
		ResetCores();
	else
		HasRefilledDeadeye = true;
}

void NerfedSleepAndBath::Initialize()
{
	Context->Logger->Write("Initializing NerfedSleepAndBath");
	LastDeadeye = Plr::GetCore(Core::Deadeye);
	LastHealth = Plr::GetCore(Core::Health);
	HasControl = true;
	HasRefilledDeadeye = false;
	Context->Logger->Write("Values set");
	Context->PlrEvents->OnSleepingChanged += [this](Util::NO_SENDER _, const bool isSleeping)
	{
		Context->Logger->Write(std::format("isSleeping changed: value = {}", isSleeping));
		OnSleepingChanged(_, isSleeping);
	};
	Context->PlrEvents->OnInControlChanged += [this](Util::NO_SENDER _, const bool isInControl)
	{
		Context->Logger->Write(std::format("isInControl changed: value = {}", isInControl));
		OnControlChanged(_, isInControl);
	};
	Context->PlrEvents->OnDeadeyeCoreChanged += [this](Util::NO_SENDER _, const int value)
	{
		Context->Logger->Write(std::format("OnDeadeyeCoreChanged changed: value = {}", value));
		OnDeadeyeChanged(_, value);
	};
	Context->Logger->Write("ChangedEvent connected");
}


// 		// START OF BATH DEADEYE ONLY PART ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// 		if (bathDeadEyeOnly)
// 		{
// 			static bool isBathing = false;
//
// 			if (PLR.IsBathing() && !isBathing) // hook bath here & get last health, stamina core
// 			{
// 				lastHealthCore = PLR.GetCore(Core::Health);
// 				lastStaminaCore = PLR.GetCore(Core::Stamina);
// 				isBathing = true;
// 				stringstream text;
// 				text << "hooked player is bathing, lastHealthCore: " << lastHealthCore << " lastStaminaCore: " << lastStaminaCore;
// 				LOGGER.Write(text.str().c_str());
// 			}
//
// 			if (isBathing) // keep setting player last health, stamina until player starts moving
// 			{
// 				PLR.SetCore(Core::Health, lastHealthCore);
// 				PLR.SetCore(Core::Stamina, lastStaminaCore);
//
// 				isBathing = (PLR.IsMoving()) ? false : true;
// 			}
// 		}
