#pragma once

#include <functional>
#include <vector>

namespace SoftCores::Util
{
	using NO_SENDER = void*;

	template	<typename Sender, typename Value>
	struct		Listener
	{
		unsigned long									ID;
		std::function<void(Sender sender, Value value)> Function;
	};


	template	<typename Sender, typename Value>
	class		Connection
	{
	public:
		unsigned long							ID;
		std::vector<Listener<Sender, Value>>	*Listeners;

		Connection(const unsigned long &id, std::vector<Listener<Sender, Value>> *listeners)
		{
			ID = id;
			Listeners = listeners;
		}

		void	Disconnect()
		{
			if (Listeners == nullptr)
				return ;
			std::erase_if(*Listeners,
				[this](Listener<Sender, Value> listener){ return (this->ID == listener.ID); });
			delete (this);
		}
	};


	// An event implementation that does not rely on inheritance.
	// Con: Type safety and defining value names.
	// Pro: Easy for creating a bunch of events for a bunch of values.
	template	<typename Sender, typename Value>
	class		Event
	{
	protected:
		std::vector<Listener<Sender, Value>>	Listeners;
	public:
		Event() = default;
		void	Dispatch(Sender sender, Value value)
		{
			for (auto listener : Listeners)
			{
				listener.Function(sender, value);
			}
		}

		Connection<Sender, Value>	*operator+=(std::function<void(Sender sender, Value value)> func)
		{
			static unsigned long	id = 0;

			Listeners.push_back(Listener<Sender, Value>{ .ID = id, .Function = func });
			id++;
			return (new Connection<Sender, Value>(id, &Listeners));
		}
	};
}
