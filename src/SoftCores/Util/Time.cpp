#include "SoftCores/Util/Time.h"
#include <chrono>

using namespace SoftCores;
using namespace std::chrono;

static unsigned long long GetNowInMilliseconds()
{
	return (duration_cast<std::chrono::milliseconds>(steady_clock::now().time_since_epoch()).count());
}

bool Util::HasDurationPassed(const unsigned long long &milliseconds, unsigned long long *counter)
{
	if (counter == nullptr)
		return (false);
	if (GetNowInMilliseconds() < *counter + milliseconds)
		return (false);
	*counter = GetNowInMilliseconds();
	return (true);
}
