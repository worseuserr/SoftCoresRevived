#pragma once
#include <vector>

namespace SoftCores::Util
{
	template	<typename Sender, typename Value>
	// An event implementation that does not rely on inheritance.
	// Con: Type safety and defining value names.
	// Pro: Easy for creating a bunch of events for a bunch of values.
	class Event
	{
	protected:
		std::vector<void *(Sender, Value)>	Listeners_;
	public:
		Event<Sender, Value>();
		void		Dispatch(Sender sender, Value value);
		Event		&operator+=(void (*func)(Sender sender, Value value));
		Event		&operator-=(void (*func)(Sender sender, Value value));
	};
}
