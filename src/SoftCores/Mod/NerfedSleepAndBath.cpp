#include <format>
#include "SoftCores/Mod/NerfedSleepAndBath.h"
#include "Debug.h"
#include "Sdk/natives.h"
#include "SoftCores/Keys.h"
#include "SoftCores/Plr.h"

using namespace SoftCores;

void NerfedSleepAndBath::ResetSleepCores()
{
	Plr::SetCore(Core::Deadeye, LastDeadeye);
	Plr::SetCore(Core::Health, LastHealth);
	HasControl = true;
	HasRefilledDeadeye = false;
}

void NerfedSleepAndBath::ResetBathCores()
{
	Plr::SetCore(Core::Stamina, LastStamina);
	Plr::SetCore(Core::Health, LastHealth);
	IsBathing = false;
}

void NerfedSleepAndBath::OnControlChanged(PlrEvents *plrEvents, const bool isInControl)
{
	if (!isInControl)
	{
		LastDeadeye = Plr::GetCore(Core::Deadeye);
		LastHealth = Plr::GetCore(Core::Health);
	}
	HasControl = isInControl;
	HasRefilledDeadeye = false;
}

void NerfedSleepAndBath::OnBathingChanged(PlrEvents *plrEvents, const bool isBathing)
{
	if (isBathing)
		IsBathing = true;
}

void NerfedSleepAndBath::OnMovingChanged(PlrEvents *plrEvents, const bool isMoving)
{
	if (IsBathing && isMoving)
		IsBathing = false;
}

void NerfedSleepAndBath::OnSleepingChanged(PlrEvents *plrEvents, const bool isSleeping)
{
	if (isSleeping && HasRefilledDeadeye)
		ResetSleepCores();
}

void NerfedSleepAndBath::OnDeadeyeChanged(PlrEvents *plrEvents, const int value)
{
	if (HasControl)
		return ;
	// This check is for when the player sets up a tent during rain, which for some reason doesn't set IsSleeping.
	if (PED::_IS_PED_USING_SCENARIO_HASH(Plr::GetPed(), Keys::GetHash("PROP_PLAYER_SLEEP_TENT_A_FRAME")))
		ResetSleepCores();
	else
		HasRefilledDeadeye = true;
}

void NerfedSleepAndBath::OnStaminaChanged(PlrEvents *plrEvents, const int value)
{
	if (IsBathing)
		ResetBathCores();
}

void NerfedSleepAndBath::Initialize()
{
	Debug::Log(LogLevel::Info, "NerfedSleepAndBath initialized");
	LastDeadeye = Plr::GetCore(Core::Deadeye);
	LastHealth = Plr::GetCore(Core::Health);
	LastStamina = Plr::GetCore(Core::Stamina);
	HasControl = true;
	IsBathing = false;
	HasRefilledDeadeye = false;
	Debug::Log(LogLevel::Debug, "Values set");
	Context->PlrEvents->OnSleepingChanged += [this](PlrEvents *plrEvents, const bool isSleeping)
	{
		Debug::Log(LogLevel::Debug, "isSleeping changed: value = {}", isSleeping);
		OnSleepingChanged(plrEvents, isSleeping);
	};
	Context->PlrEvents->OnControlChanged += [this](PlrEvents *plrEvents, const bool isInControl)
	{
		Debug::Log(LogLevel::Debug, "isInControl changed: value = {}", isInControl);
		OnControlChanged(plrEvents, isInControl);
	};
	Context->PlrEvents->OnBathingChanged += [this](PlrEvents *plrEvents, const bool isBathing)
	{
		Debug::Log(LogLevel::Debug, "OnBathingChanged changed: value = {}", isBathing);
		OnBathingChanged(plrEvents, isBathing);
	};
	Context->PlrEvents->OnDeadeyeCoreChanged += [this](PlrEvents *plrEvents, const int value)
	{
		Debug::Log(LogLevel::Debug, "OnDeadeyeCoreChanged changed: value = {}", value);
		OnDeadeyeChanged(plrEvents, value);
	};
	Context->PlrEvents->OnStaminaCoreChanged += [this](PlrEvents *plrEvents, const int value)
	{
		Debug::Log(LogLevel::Debug, "OnStaminaCoreChanged changed: value = {}", value);
		OnStaminaChanged(plrEvents, value);
	};
	Context->PlrEvents->OnMovingChanged += [this](PlrEvents *plrEvents, const bool isMoving)
	{
		Debug::Log(LogLevel::Debug, "OnMovingChanged changed: value = {}", isMoving);
		OnMovingChanged(plrEvents, isMoving);
	};
	Debug::Log(LogLevel::Debug, "ChangedEvents connected");
}
