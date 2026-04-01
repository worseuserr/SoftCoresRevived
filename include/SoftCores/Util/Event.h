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
		std::vector<void (*)(Sender, Value)>	Listeners_;
	public:
		Event() = default;
		void		Dispatch(Sender sender, Value value)
		{
			for (auto func : Listeners_)
			{
				func(sender, value);
			}
		}

		Event		&operator+=(void (*func)(Sender sender, Value value))
		{
			Listeners_.push_back(func);
			return (*this);
		}

		Event		&operator-=(void (*func)(Sender sender, Value value))
		{
			std::erase(Listeners_, func);
			return (*this);
		}
	};
}
