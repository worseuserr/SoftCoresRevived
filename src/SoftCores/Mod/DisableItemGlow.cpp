#include "SoftCores/Mod/DisableItemGlow.h"
#include "Debug.h"
#include "Sdk/natives.h"
#include "Sdk/types.h"
#include "SoftCores/World.h"
#include "SoftCores/Util/Time.h"

using namespace SoftCores;

DisableItemGlow::DisableItemGlow(ModContext *context)
	: Feature(context) {}

// Note: perhaps there's no need to call the native more than once, needs testing.
void DisableItemGlow::OnTick(Util::NO_SENDER _, const float dTime)
{
	static constexpr int	RANGE = 512;
	Pickup	pickups[RANGE];
	Object	objects[RANGE];
	int		i;

	// Only run every <interval> ms.
	if (!Util::HasDurationPassed(Interval, &Counter))
		return ;
	if (Context->Config->Immersion.DisablePickupGlow)
		for (i = 0; i < World::GetAllPickups(pickups, RANGE); i++)
			// GRAPHICS::_0x50C14328119E1DD1 disables the glow for both pickups and objects.
			GRAPHICS::_0x50C14328119E1DD1(pickups[i], true);
	if (Context->Config->Immersion.DisableObjectGlow) // Disables lootable objects such as provisions and tonics.
		for (i = 0; i < World::GetAllObjects(objects, RANGE); i++)
			GRAPHICS::_0x50C14328119E1DD1(objects[i], true);
}

void DisableItemGlow::Initialize()
{
	Debug::Log(LogLevel::Info, "DisableItemGlow initialized");

	Context->Tick->OnTick += [this](Util::NO_SENDER _, const float dTime) { OnTick(_, dTime); };
}
