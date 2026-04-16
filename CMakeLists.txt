cmake_minimum_required(VERSION 4.2)
project(SoftCoresRevived)

set(CMAKE_CXX_STANDARD 20)

include_directories(
		include
		sdk/inc
)

link_directories(
		sdk/lib
)

add_library(SoftCoresRevived SHARED
		src/Main.cpp
		include/Keyboard.h
		include/Script.h
		include/SoftCores/Weapons.h
		include/SoftCores/World.h
		include/SoftCores/UI.h
		include/SoftCores/Tick.h
		include/SoftCores/Temperature.h
		include/SoftCores/Plr.h
		include/SoftCores/Keys.h
		include/SoftCores/Enums.h
		include/SoftCores/Config.h
		include/SoftCores/Util/Math.h
		include/SoftCores/Util/Logger.h
		include/SoftCores/Util/File.h
		include/SoftCores/Util/Event.h
		src/Script.cpp
		src/Keyboard.cpp
		src/SoftCores/World.cpp
		src/SoftCores/Weapons.cpp
		src/SoftCores/UI.cpp
		src/SoftCores/Tick.cpp
		src/SoftCores/Temperature.cpp
		src/SoftCores/Plr.cpp
		src/SoftCores/Keys.cpp
		src/SoftCores/Config.cpp
		src/SoftCores/Util/Math.cpp
		src/SoftCores/Util/Logger.cpp
		src/SoftCores/Util/File.cpp
		include/SoftCores/Mod/Mod.h
		src/SoftCores/Mod/Feature.cpp
		src/SoftCores/Mod/Mod.cpp
		src/SoftCores/Mod/FXOverride.cpp
		include/SoftCores/Mod/FXOverride.h
		include/SoftCores/Mod/FOVBlips.h
		src/SoftCores/Mod/FOVBlips.cpp
		include/SoftCores/Util/Time.h
		src/SoftCores/Util/Time.cpp
		src/SoftCores/Mod/NerfedSleepAndBath.cpp
		include/SoftCores/Mod/NerfedSleepAndBath.h
		include/SoftCores/PlrEvents.h
		include/SoftCores/ModContext.h
		include/Debug.h
		src/Debug.cpp
		include/SoftCores/Mod/DisableItemGlow.h
		src/SoftCores/Mod/DisableItemGlow.cpp
		include/SoftCores/Mod/NoDeadeyeReload.h
		src/SoftCores/Mod/NoDeadeyeReload.cpp
)

target_compile_options(SoftCoresRevived PRIVATE
		/EHsc
		/O2
)

target_link_libraries(SoftCoresRevived PRIVATE ScriptHookRDR2.lib)

set_target_properties(SoftCoresRevived PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
		SUFFIX ".asi"
)

configure_file(config/SoftCoresRevived.ini ${PROJECT_SOURCE_DIR}/bin COPYONLY)
