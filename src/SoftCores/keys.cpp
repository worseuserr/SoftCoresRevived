#include <SoftCores/Keys.h>
#include <Sdk/natives.h>

using namespace SoftCores::Keys;

Key::Key(std::string str)
{
	keyString = str;
}

Key::Key(const char *str)
{
	keyString = std::string(str);
}

Hash Key::Hash()
{
	return (MISC::GET_HASH_KEY(ToCString()));
}

const char *Key::ToCString()
{
	return (keyString.c_str());
}

Hash SoftCores::Keys::GetHash(const char *str)
{
	return (Key(str).Hash());
}
