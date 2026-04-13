#include "SoftCores/Mod/NerfedSleepAndBath.h"

#include <format>

#include "Debug.h"
#include "Sdk/natives.h"
#include "SoftCores/Keys.h"
#include "SoftCores/Plr.h"

using namespace SoftCores;

NerfedSleepAndBath::NerfedSleepAndBath(ModContext *context)
	: Feature(context), LastDeadeye(0), LastHealth(0), LastStamina(0),
	HasControl(false), HasRefilledDeadeye(false), IsBathing(false)
{
}

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

void NerfedSleepAndBath::OnBathingChanged(Util::NO_SENDER _, bool isBathing)
{
	if (isBathing)
		IsBathing = true;
}

void NerfedSleepAndBath::OnMovingChanged(Util::NO_SENDER _, bool isMoving)
{
	if (IsBathing && isMoving)
		IsBathing = false;
}

void NerfedSleepAndBath::OnSleepingChanged(Util::NO_SENDER _, const bool isSleeping)
{
	if (isSleeping && HasRefilledDeadeye)
		ResetSleepCores();
}

void NerfedSleepAndBath::OnDeadeyeChanged(Util::NO_SENDER _, const int value)
{
	if (HasControl)
		return ;
	// This check is for when the player sets up a tent during rain, which for some reason doesn't set IsSleeping.
	if (PED::_IS_PED_USING_SCENARIO_HASH(Plr::GetPed(), Keys::GetHash("PROP_PLAYER_SLEEP_TENT_A_FRAME")))
		ResetSleepCores();
	else
		HasRefilledDeadeye = true;
}

void NerfedSleepAndBath::OnStaminaChanged(Util::NO_SENDER _, int value)
{
	if (IsBathing)
		ResetBathCores();
}

void NerfedSleepAndBath::Initialize()
{
	Debug::Log(LogLevel::Info, "Initializing NerfedSleepAndBath");
	LastDeadeye = Plr::GetCore(Core::Deadeye);
	LastHealth = Plr::GetCore(Core::Health);
	LastStamina = Plr::GetCore(Core::Stamina);
	HasControl = true;
	IsBathing = false;
	HasRefilledDeadeye = false;
	Debug::Log(LogLevel::Debug, "Values set");
	Context->PlrEvents->OnSleepingChanged += [this](Util::NO_SENDER _, const bool isSleeping)
	{
		Debug::Log(LogLevel::Debug, "isSleeping changed: value = {}", isSleeping);
		OnSleepingChanged(_, isSleeping);
	};
	Context->PlrEvents->OnControlChanged += [this](Util::NO_SENDER _, const bool isInControl)
	{
		Debug::Log(LogLevel::Debug, "isInControl changed: value = {}", isInControl);
		OnControlChanged(_, isInControl);
	};
	Context->PlrEvents->OnBathingChanged += [this](Util::NO_SENDER _, const bool isBathing)
	{
		Debug::Log(LogLevel::Debug, "OnBathingChanged changed: value = {}", isBathing);
		OnBathingChanged(_, isBathing);
	};
	Context->PlrEvents->OnDeadeyeCoreChanged += [this](Util::NO_SENDER _, const int value)
	{
		Debug::Log(LogLevel::Debug, "OnDeadeyeCoreChanged changed: value = {}", value);
		OnDeadeyeChanged(_, value);
	};
	Context->PlrEvents->OnStaminaCoreChanged += [this](Util::NO_SENDER _, const int value)
	{
		Debug::Log(LogLevel::Debug, "OnStaminaCoreChanged changed: value = {}", value);
		OnStaminaChanged(_, value);
	};
	Context->PlrEvents->OnMovingChanged += [this](Util::NO_SENDER _, const bool isMoving)
	{
		Debug::Log(LogLevel::Debug, "OnMovingChanged changed: value = {}", isMoving);
		OnMovingChanged(_, isMoving);
	};
	Debug::Log(LogLevel::Debug, "ChangedEvents connected");
}
