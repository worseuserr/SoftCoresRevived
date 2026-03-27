#pragma once

#include <string>
#include <array>
#include "types.h"

namespace SoftCores
{
	namespace Keys
	{
		class Key
		{
		public:
			std::string	keyString;

			Key(std::string str);
			Hash		Hash();
			const char	*ToCString();
		};

		Hash	GetHash(const char *str);

		const std::array<Key, 15>	CampScenarios = {
			Key("WORLD_PLAYER_CAMP_FIRE_KNEEL1"),
			Key("WORLD_PLAYER_CAMP_FIRE_KNEEL2"),
			Key("WORLD_PLAYER_CAMP_FIRE_KNEEL3"),
			Key("WORLD_PLAYER_CAMP_FIRE_KNEEL4"),
			Key("WORLD_PLAYER_CAMP_FIRE_SIT"),
			Key("WORLD_PLAYER_CAMP_FIRE_SQUAT"),
			Key("WORLD_PLAYER_DYNAMIC_KNEEL_KNIFE"),
			Key("WORLD_PLAYER_CAMP_FIRE_SQUAT_MALE_A"),
			Key("WORLD_PLAYER_CAMP_FIRE_SIT_MALE_A"),
			Key("WORLD_PLAYER_DYNAMIC_CAMP_FIRE_KNEEL_ARTHUR"),
			Key("PROP_PLAYER_SLEEP_TENT_A_FRAME"),
			Key("PROP_PLAYER_SEAT_CHAIR_PLAYER_CAMP"),
			Key("PROP_PLAYER_SEAT_CHAIR_DYNAMIC"),
			Key("PROP_PLAYER_SEAT_CHAIR_GENERIC"),
			Key("PROP_PLAYER_SEAT_CHAIR_GENERIC_CA")
		};

		const std::array<Key, 11>	SleepScenarios = {
			Key("WORLD_PLAYER_SLEEP_BEDROLL"),
			Key("WORLD_PLAYER_SLEEP_BEDROLL_ARTHUR"),
			Key("WORLD_PLAYER_SLEEP_GROUND"),
			Key("PROP_PLAYER_SLEEP_BED"),
			Key("PROP_PLAYER_SLEEP_BED_ARTHUR"),
			Key("PROP_PLAYER_SLEEP_TENT_A_FRAME"),
			Key("PROP_PLAYER_SLEEP_TENT_A_FRAME_ARTHUR"),
			Key("PROP_PLAYER_SLEEP_TENT_MALE_A"),
			Key("PROP_PLAYER_SLEEP_TENT_MALE_A_ARTHUR"),
			Key("PROP_PLAYER_SLEEP_A_FRAME_TENT_PLAYER_CAMPS"),
			Key("PROP_PLAYER_SLEEP_A_FRAME_TENT_PLAYER_CAMPS_ARTHUR")
		};

		const std::array<Key, 44>	FriendlyPeds = {
			Key("CS_ABIGAILROBERTS"),
			Key("CS_BEATENUPCAPTAIN"),
			Key("CS_BILLWILLIAMSON"),
			Key("CS_BROTHERDORKINS"),
			Key("CS_CAPTAINMONROE"),
			Key("CS_CHARLESSMITH"),
			Key("CS_CLAY"),
			Key("CS_CLEET"),
			Key("CS_CLIVE"),
			Key("CS_DUTCH"),
			Key("CS_EAGLEFLIES"),
			Key("CS_EDITHDOWN"),
			Key("CS_HAMISH"),
			Key("CS_HERCULE"),
			Key("CS_HOSEAMATTHEWS"),
			Key("CS_JACKMARSTON"),
			Key("CS_JACKMARSTON_TEEN"),
			Key("CS_JAMIE"),
			Key("CS_JAVIERESCUELLA"),
			Key("CS_JOE"),
			Key("CS_JOHNMARSTON"),
			Key("CS_JOSIAHTRELAWNY"),
			Key("CS_JULES"),
			Key("CS_KAREN"),
			Key("CS_LEMIUXASSISTANT"),
			Key("CS_LENNY"),
			Key("CS_LEON"),
			Key("CS_LEOSTRAUSS"),
			Key("CS_MAGNIFICO"),
			Key("CS_MARYBETH"),
			Key("CS_MICAHBELL"),
			Key("CS_MOLLYOSHEA"),
			Key("CS_MRPEARSON"),
			Key("CS_MRSADLER"),
			Key("CS_PAYTAH"),
			Key("CS_PRINCESSISABEAU"),
			Key("CS_RAINSFALL"),
			Key("CS_REVSWANSON"),
			Key("CS_SEAN"),
			Key("CS_SISTERCALDERON"),
			Key("CS_SUSANGRIMSHAW"),
			Key("CS_THOMASDOWN"),
			Key("CS_TILLY"),
			Key("CS_UNCLE")
		};
	}
}
