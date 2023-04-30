#include "Hook.h"

namespace QuickSave
{
	void SystemQuickSaveHook::ProcessQuickSave(RE::BGSSaveLoadManager* a_manager, std::uint32_t a_flag)
	{
		static constexpr std::uint32_t regular_save = 0xF0000080;
		return _ProcessQuickSave(a_manager, regular_save);
	}
}