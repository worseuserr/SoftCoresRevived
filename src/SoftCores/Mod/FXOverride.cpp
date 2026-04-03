#include "SoftCores/Mod/FXOverride.h"
#include "Sdk/natives.h"
#include "SoftCores/Tick.h"

using namespace SoftCores;

FXOverride::FXOverride(Util::Logger *logger, SoftCores::Config *config)
	: Feature(logger, config), TickConnection(nullptr) {}

void FXOverride::Tick(void *_, float dTime) const
{
	const FXConfig	&FX = Config->FX;

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
	Logger->Write("FXOverride initialized.");
	if (!Config->FX.Enabled)
		return ;
	Logger->Write("FX.Enabled check passed.");
	TickConnection = Tick::OnTick += [this](void *_, const float dTime){ Tick(_, dTime); };
}
