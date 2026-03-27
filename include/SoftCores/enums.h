#pragma once
#include <natives.h>

namespace SoftCores {
	enum class Core {
		Health,
		Stamina,
		DeadEye
	};

	enum class ClothingType : uint {
		Hats = 0x9925C067,
		Shirts = 0x2026C46D,
		Vests = 0x485EE834,
		Pants = 0x1D4C528A,
		Boots = 0x777EC6EF,
		Cloaks = 0x3C1A74CD,
		Neckwear = 0x5FC29285,
		Neckties = 0x7A96FACA,
		Gloves = 0xEABE0032,
		Coats = 0xE06D30CE,
		Chaps = 0x3107499B
	};
}
