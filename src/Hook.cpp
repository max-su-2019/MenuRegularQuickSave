#include "Hook.h"

namespace QuickSave
{
	void SystemQuickSaveHook::ProcessQuickSave(RE::BGSSaveLoadManager* a_manager, std::uint32_t a_flag)
	{
		static constexpr std::uint32_t button_regular_save = 0xF0000080;
		_ProcessQuickSave(a_manager, button_regular_save);
		return RE::UIMessageQueue::GetSingleton()->AddMessage(RE::JournalMenu::MENU_NAME, RE::UI_MESSAGE_TYPE::kHide, nullptr);
	}
}