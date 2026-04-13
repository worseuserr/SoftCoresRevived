#include <SoftCores/Weapons.h>
#include <Sdk/natives.h>
#include <SoftCores/Keys.h>
#include <Sdk/types.h>

using namespace SoftCores;

bool Weapons::IsItem(const Hash weapon)
{
	for (Keys::Key key : Keys::ItemWeapons)
	{
		if (MISC::ARE_STRINGS_EQUAL(WEAPON::_GET_WEAPON_NAME(weapon), key.ToCString()))
			return (true);
	}
	return (false);
}

bool Weapons::IsExotic(const Hash weapon)
{
	for (Keys::Key key : Keys::ExoticWeapons)
	{
		if (MISC::ARE_STRINGS_EQUAL(WEAPON::_GET_WEAPON_NAME(weapon), key.ToCString()))
			return (true);
	}
	return (false);
}

bool Weapons::IsThrowableOnly(const Hash weapon)
{


	for (Keys::Key key : Keys::ThrowableWeapons)
	{
		if (MISC::ARE_STRINGS_EQUAL(WEAPON::_GET_WEAPON_NAME(weapon), key.ToCString()))
			return (true);
	}
	return (false);
}

bool Weapons::IsMelee(const Hash weapon)
{

	for (Keys::Key key : Keys::MeleeWeapons)
	{
		if (MISC::ARE_STRINGS_EQUAL(WEAPON::_GET_WEAPON_NAME(weapon), key.ToCString()))
			return (true);
	}
	return (false);
}
