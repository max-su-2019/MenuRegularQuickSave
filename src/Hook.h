#pragma once

namespace QuickSave
{
	class SystemQuickSaveHook
	{
	public:
		static void Hook()
		{
			REL::Relocation<uintptr_t> hook{ REL::ID(52378) };  //1408ef6f0		1.5.97
			auto& trampoline = SKSE::GetTrampoline();
			SKSE::AllocTrampoline(1 << 4);
			_ProcessQuickSave = trampoline.write_branch<5>(hook.address() + 0x26, ProcessQuickSave);
		};

	private:
		static void ProcessQuickSave(RE::BGSSaveLoadManager* a_manager, std::uint32_t a_flag);

		static inline REL::Relocation<decltype(ProcessQuickSave)> _ProcessQuickSave;
	};
}