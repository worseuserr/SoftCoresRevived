#include <SoftCores/UI.h>
#include <Sdk/natives.h>

using namespace SoftCores;

void UI::TogglePrompt(int prompt, bool visible, bool enabled)
{
	HUD::_UIPROMPT_SET_VISIBLE(prompt, visible);
	HUD::_UIPROMPT_SET_ENABLED(prompt, enabled);
}
