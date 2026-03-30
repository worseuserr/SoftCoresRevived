#include <SoftCores/Plr.h>
#include <SoftCores/Keys.h>
#include <SoftCores/Util/Math.h>
#include <Sdk/natives.h>

using namespace SoftCores;
using namespace SoftCores::Util;
using namespace Keys;

int Plr::GetMaxOuterCore(Core core)
{
	return (ATTRIBUTE::GET_MAX_ATTRIBUTE_POINTS(PLAYER::PLAYER_PED_ID(), static_cast<int>(core)));
}

int Plr::GetOuterCore(Core core)
{
	return (ATTRIBUTE::GET_ATTRIBUTE_POINTS(PLAYER::PLAYER_PED_ID(), static_cast<int>(core)));
}

void Plr::SetOuterCore(Core core, int value)
{
	ATTRIBUTE::SET_ATTRIBUTE_POINTS(PLAYER::PLAYER_PED_ID(), static_cast<int>(core), value);
}

int Plr::GetCore(Core core)
{
	return (ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(PLAYER::PLAYER_PED_ID(), static_cast<int>(core)));
}

void Plr::SetCore(Core core, int value)
{
	ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(PLAYER::PLAYER_PED_ID(), static_cast<int>(core), value);
}

int Plr::GetHorseCore(Core core)
{
	return (ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(PLAYER::_GET_SADDLE_HORSE_FOR_PLAYER(PLAYER::PLAYER_ID()), static_cast<int>(core)));
}


void Plr::SetHorseCore(Core core, int value)
{
	ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(PLAYER::_GET_SADDLE_HORSE_FOR_PLAYER(PLAYER::PLAYER_ID()), static_cast<int>(core), value);
}

bool Plr::IsCoreOverpowered(Core core)
{
	return (ATTRIBUTE::_0x200373A8DF081F22(PLAYER::PLAYER_PED_ID(), static_cast<int>(core)));
}

bool Plr::IsOuterCoreOverpowered(Core core)
{
	return (ATTRIBUTE::_IS_ATTRIBUTE_OVERPOWERED(PLAYER::PLAYER_PED_ID(), static_cast<int>(core)));
}

bool Plr::IsHorseCoreOverpowered(Core core)
{
	return (ATTRIBUTE::_0x200373A8DF081F22(PLAYER::_GET_SADDLE_HORSE_FOR_PLAYER(PLAYER::PLAYER_PED_ID()), static_cast<int>(core)));
}

void SoftCores::Plr::SetDamageModifier(float melee, float weapon)
{
	PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(PLAYER::PLAYER_ID(), melee);
	PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(PLAYER::PLAYER_ID(), weapon);
}

void Plr::SetHealthRegen(float multiplier)
{
	PLAYER::SET_PLAYER_HEALTH_RECHARGE_MULTIPLIER(PLAYER::PLAYER_ID(), multiplier);
}

void Plr::UnequipClothes(ClothingType type)
{
	PED::_SET_PED_COMPONENT_DISABLED(PLAYER::PLAYER_PED_ID(), static_cast<uint>(type), 1);
	PED::_UPDATE_PED_VARIATION(PLAYER::PLAYER_PED_ID(), false, true, true, true, false);
}

bool Plr::IsWearing(ClothingType type)
{
	return (PED::_IS_METAPED_USING_COMPONENT(PLAYER::PLAYER_PED_ID(), static_cast<uint>(type)));
}

bool Plr::IsAlive()
{
	return !(PLAYER::IS_PLAYER_DEAD(PLAYER::PLAYER_ID()) || ENTITY::IS_ENTITY_DEAD(PLAYER::PLAYER_PED_ID()));
}

bool Plr::IsPlaying()
{
	return (PLAYER::IS_PLAYER_PLAYING(PLAYER::PLAYER_ID()) && ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()));
}

bool Plr::IsInMission()
{
	return (MISC::GET_MISSION_FLAG() || MISC::IS_MINIGAME_IN_PROGRESS() || GRAPHICS::ANIMPOSTFX_IS_RUNNING("MissionFail01"));
}

// If player can control their character. Maps to `PLAYER::IS_PLAYER_CONTROL_ON(Player player)`
bool Plr::IsInControl()
{
	return (PLAYER::IS_PLAYER_CONTROL_ON(PLAYER::PLAYER_ID()));
}

bool Plr::IsPursued()
{
	return (PLAYER::GET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID()) > 0);
}

bool Plr::IsActiveInScenario()
{
	return (TASK::IS_PED_ACTIVE_IN_SCENARIO(PLAYER::PLAYER_PED_ID(), 0));
}

bool Plr::IsUsingAnyScenario()
{
	return (PED::IS_PED_USING_ANY_SCENARIO(PLAYER::PLAYER_PED_ID()));
}

bool Plr::IsBathing()
{
	return (MISC::ARE_STRINGS_EQUAL(TASK::GET_TASK_MOVE_NETWORK_STATE(PLAYER::PLAYER_PED_ID()), "Bathing"));
}

bool Plr::IsInCombat()
{
	return (PED::IS_PED_IN_COMBAT(PLAYER::PLAYER_PED_ID(), NULL) || PED::IS_PED_IN_MELEE_COMBAT(PLAYER::PLAYER_PED_ID()));
}

bool Plr::IsPedHostileAndNearby(Ped ped)
{
	Vector3	playerPos;

	playerPos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true, true);
	return (PED::IS_ANY_HOSTILE_PED_NEAR_POINT(ped, playerPos.x, playerPos.y, playerPos.z, 100.0f));
}

bool Plr::IsIdle()
{
	Ped	playerPed;

	playerPed = PLAYER::PLAYER_PED_ID();
	return (TASK::IS_PED_STILL(playerPed) && !TASK::IS_PED_WALKING(playerPed) && !TASK::IS_PED_RUNNING(playerPed) && !TASK::IS_PED_SPRINTING(playerPed));
}

bool Plr::IsMounted()
{
	return (PED::IS_PED_ON_MOUNT(PLAYER::PLAYER_PED_ID()));
}

bool Plr::IsInCover()
{
	return (PED::IS_PED_IN_COVER(PLAYER::PLAYER_PED_ID(), true, true));
}

bool SoftCores::Plr::IsDeadeyeActivated()
{
	return (PAD::IS_CONTROL_JUST_PRESSED(0, Key("INPUT_SPECIAL_ABILITY").Hash())
		|| PAD::IS_CONTROL_PRESSED(0, Key("INPUT_SPECIAL_ABILITY").Hash())
		|| PAD::IS_CONTROL_JUST_PRESSED(0, Key("INPUT_SPECIAL_ABILITY_PC").Hash())
		|| PAD::IS_CONTROL_PRESSED(0, Key("INPUT_SPECIAL_ABILITY_PC").Hash()));
}

bool Plr::IsIndoors()
{
	return ((INTERIOR::GET_INTERIOR_FROM_ENTITY(PLAYER::PLAYER_PED_ID()) != 0) ? true : false);
}

bool Plr::IsSubmerged()
{
	return (ENTITY::IS_ENTITY_IN_WATER(PLAYER::PLAYER_PED_ID())
		|| ENTITY::GET_ENTITY_SUBMERGED_LEVEL(PLAYER::PLAYER_PED_ID()) > 0.0f);
}

bool Plr::IsMoving()
{
	Ped	playerPed;

	playerPed = PLAYER::PLAYER_PED_ID();
	return (IsInControl()
		&& (TASK::IS_PED_WALKING(playerPed)
			|| TASK::IS_PED_RUNNING(playerPed)
			|| TASK::IS_PED_SPRINTING(playerPed)
			|| TASK::IS_PED_GETTING_UP(playerPed)
			|| !TASK::IS_PED_STILL(playerPed)
			|| PED::IS_PED_GETTING_INTO_A_VEHICLE(playerPed)
			|| PED::_IS_PED_GETTING_INTO_A_MOUNT_SEAT(playerPed, true)));
}

bool Plr::IsInCampScenario()
{
	for (Key scenario : CampScenarios)
	{
		if (PED::_IS_PED_USING_SCENARIO_HASH(PLAYER::PLAYER_PED_ID(), scenario.Hash()) && TASK::_GET_SCENARIO_POINT_PED_IS_USING(PLAYER::PLAYER_PED_ID(), 1) == -1)
			return (true);
	}
	return (false);
}

bool Plr::IsInSleepScenario()
{
	for (Key scenario : SleepScenarios)
	{
		if (PED::_IS_PED_USING_SCENARIO_HASH(PLAYER::PLAYER_PED_ID(), scenario.Hash()) && TASK::_GET_SCENARIO_POINT_PED_IS_USING(PLAYER::PLAYER_PED_ID(), 1) == -1)
		{
			return true;
			break;
		}
	}
	return false;
}

float Plr::GetClothingTemperaturePoints()
{
	float	clothPoints;

	clothPoints = 0;
	if (IsWearing(ClothingType::Hats)) clothPoints += 0.2f; // can be removed
	if (IsWearing(ClothingType::Shirts)) clothPoints += 0.8f; // by default, assured points, can't be removed
	if (IsWearing(ClothingType::Vests)) clothPoints += 1.0f; // can be removed
	if (IsWearing(ClothingType::Pants)) clothPoints += 0.8f; // by default, assured points, can't be removed
	if (IsWearing(ClothingType::Boots)) clothPoints += 1.2f; // can be removed
	if (IsWearing(ClothingType::Cloaks)) clothPoints += 1.6f; // by default, only a Cloaks/Coats at a time
	if (IsWearing(ClothingType::Coats)) clothPoints += 1.6f;
	if (IsWearing(ClothingType::Neckwear)) clothPoints += 0.2f; // by default, only a Neckwear/Neckties at a time
	if (IsWearing(ClothingType::Neckties)) clothPoints += 0.2f;
	if (IsWearing(ClothingType::Gloves)) clothPoints += 0.6f; // can be removed
	if (IsWearing(ClothingType::Chaps)) clothPoints += 0.4f; // can be removed

	return (clothPoints);
	// by default, full outfit will be 8.0f
	// basic outfit hat, shirt, pants & boots = 2.8f
	// basic outfit with vests & neckwear = 4.2f
	// plus gloves and chaps = 5.2f
}

float Plr::GetSurroundingTemperature()
{
	Vector3 playerPos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true, true);
	float temperature = MISC::_GET_TEMPERATURE_AT_COORDS(playerPos.x, playerPos.y, playerPos.z); // this function return in celcius

	return (MISC::_SHOULD_USE_METRIC_TEMPERATURE()) ? temperature: Math::CelciusToFarenheit(temperature);
}

