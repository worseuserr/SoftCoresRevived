#include "SoftCores/Mod/FXOverride.h"
#include "Sdk/natives.h"
#include "SoftCores/Tick.h"

using namespace SoftCores;

FXOverride::FXOverride(ModContext *context)
	: Feature(context) {}

void FXOverride::Tick(Util::NO_SENDER _, float dTime) const
{
	const FXConfig	&FX = Context->Config->FX;

	if (!Context->Config->FX.Enabled)
		return ;
	if (!FX.EmptyHealth) GRAPHICS::ANIMPOSTFX_STOP("PlayerRPGEmptyCoreHealth");
	if (!FX.EmptyStamina) GRAPHICS::ANIMPOSTFX_STOP("PlayerRPGEmptyCoreStamina");
	if (!FX.Deadeye) GRAPHICS::ANIMPOSTFX_STOP("PlayerRPGEmptyCoreDeadEye");
	if (!FX.Overpower) GRAPHICS::ANIMPOSTFX_STOP("PlayerOverpower");
	if (!FX.Duel) GRAPHICS::ANIMPOSTFX_STOP("Duel");
	if (!FX.Deadeye) GRAPHICS::ANIMPOSTFX_STOP("deadeye");
	if (!FX.EmptyDeadEye) GRAPHICS::ANIMPOSTFX_STOP("DeadEyeEmpty");
	if (!FX.Eagleeye) GRAPHICS::ANIMPOSTFX_STOP("EagleEye");
	if (!FX.WeaponWheel) GRAPHICS::ANIMPOSTFX_STOP("WheelHUDIn");
	if (!FX.KillCam) GRAPHICS::ANIMPOSTFX_STOP("killCam");
	if (!FX.KillCam) GRAPHICS::ANIMPOSTFX_STOP("KillCamHonorChange");
	if (!FX.Death) GRAPHICS::ANIMPOSTFX_STOP("DeathFailMP01");
	if (!FX.MissionFail) GRAPHICS::ANIMPOSTFX_STOP("MissionFail01");
}

void FXOverride::Initialize()
{
	Context->Logger->Write("FXOverride initialized");
	TickConnection = Context->Tick->OnTick += [this](Util::NO_SENDER _, const float dTime){ Tick(_, dTime); };
}
