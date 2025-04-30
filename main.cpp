#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <Windows.h>
#include <cstdint>
#include <thread>
#include "functions.h"

// global vars
uintptr_t baseAddress = (uintptr_t)GetModuleHandleA("ac_client.exe");
CEnt* player = NULL;
bool infAmmoEnabled = false;
extern uintptr_t baseAddress;

void CheatThread(HMODULE instance) noexcept
{
    AllocConsole();
    FILE* f = nullptr;
    freopen_s(&f, "CONOUT$", "w", stdout);

    while (!GetAsyncKeyState(VK_F10))
    {
        Sleep(5);
        if (GetAsyncKeyState(VK_F1) & 8000)
        {
            ToggleInfAmmo();
            if (infAmmoEnabled)
                MaintainInfAmmo();
        }

    }

    if (f) fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(instance, 0);
}

int __stdcall DllMain(HMODULE instance, std::uintptr_t reason, const void* reserved)
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(instance);
        const auto thread = CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(CheatThread), instance, 0, nullptr);
        if (thread) CloseHandle(thread);
        break;
    }

    return TRUE;
}