#include "Debug.h"

SoftCores::Util::Logger*	Debug::Logger = nullptr;

void	Debug::SetLogger(SoftCores::Util::Logger &logger)
{
	Logger = &logger;
}
