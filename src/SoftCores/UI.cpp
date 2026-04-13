#include <SoftCores/UI.h>
#include <Sdk/natives.h>

using namespace SoftCores;

void UI::TogglePrompt(const int prompt, const bool visible, const bool enabled)
{
	HUD::_UIPROMPT_SET_VISIBLE(prompt, visible);
	HUD::_UIPROMPT_SET_ENABLED(prompt, enabled);
}
