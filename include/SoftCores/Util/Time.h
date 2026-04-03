#pragma once

namespace SoftCores::Util
{
	// Returns true after every <milliseconds> milliseconds pass, otherwise false. Updates counter on every true. Counter must be initialized.
	bool	HasDurationPassed(const unsigned long long &milliseconds, unsigned long long *counter);
}
