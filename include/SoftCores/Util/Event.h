#pragma once
#include <vector>

namespace SoftCores::Util
{
	using NO_SENDER = void*;

	template	<typename Sender, typename Value>
	// An event implementation that does not rely on inheritance.
	// Con: Type safety and defining value names.
	// Pro: Easy for creating a bunch of events for a bunch of values.
	class Event
	{
	protected:
		std::vector<void (*)(Sender, Value)>	Listeners;
	public:
		Event() = default;
		void		Dispatch(Sender sender, Value value)
		{
			for (auto func : Listeners)
			{
				func(sender, value);
			}
		}

		Event		&operator+=(void (*func)(Sender sender, Value value))
		{
			Listeners.push_back(func);
			return (*this);
		}

		Event		&operator-=(void (*func)(Sender sender, Value value))
		{
			std::erase(Listeners, func);
			return (*this);
		}
	};
}
