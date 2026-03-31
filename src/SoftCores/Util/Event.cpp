#include <SoftCores/Util/Event.h>
#include <vector>

using namespace SoftCores::Util;

template	<typename Sender, typename Value>
Event<Sender, Value>::Event() = default;

template	<typename Sender, typename Value>
void	Event<Sender, Value>::Dispatch(Sender sender, Value value)
{
	for (auto func : Listeners_)
	{
		func(sender, value);
	}
}

template	<typename Sender, typename Value>
Event<Sender, Value>	&Event<Sender, Value>::operator+=(void (*func)(Sender sender, Value value))
{
	Listeners_.push_back(func);
	return (this);
}

template	<typename Sender, typename Value>
Event<Sender, Value>	&Event<Sender, Value>::operator-=(void (*func)(Sender sender, Value value))
{
	std::erase(Listeners_, func);
	return (this);
}
