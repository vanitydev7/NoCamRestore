#include "main.h"

void mem::set_uchar(std::uintptr_t addr, std::uint8_t value)
{
    DWORD old_protect;
    VirtualProtect(reinterpret_cast<void*>(addr), 1, PAGE_EXECUTE_READWRITE, &old_protect);
    *reinterpret_cast<uint8_t*>(addr) = value;
    VirtualProtect(reinterpret_cast<void*>(addr), 1, old_protect, &old_protect);
}