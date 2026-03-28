#pragma once
#include "types.h"

namespace SoftCores
{
	namespace Weapons
	{
		// Items that are categorized as weapons but aren't actually.
		bool	IsItem(Hash weapon);
		// Unique weapons like the gambler's double action revolver or the rolling block exotic sniper rifle.
		bool	IsExotic(Hash weapon);
		bool	IsThrowableOnly(Hash weapon);
		bool	IsMelee(Hash weapon);
	}
}
