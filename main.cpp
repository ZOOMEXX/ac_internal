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
bool zeroDelayEnabled = false;
bool thread1Running = true;

void CheatThread(HMODULE instance) noexcept
{
    AllocConsole();
    FILE* f = nullptr;
    freopen_s(&f, "CONOUT$", "w", stdout);

    while (!GetAsyncKeyState(VK_F10))
    {
        Sleep(5);
        if (GetAsyncKeyState(VK_F1) & 0x8000)
        {
            ToggleInfAmmo();
            if (infAmmoEnabled)
                MaintainInfAmmo();
        }

    }

    Sleep(100);
    while (thread1Running)
    {
        std::cout << "Cannot uninject yet! Threads still running.\n";
        Sleep(100);
    }
    if (f) fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(instance, 0);
}

void ZeroDelayThread(HMODULE instance) noexcept
{
    while (!GetAsyncKeyState(VK_F10))
    {
        Sleep(5);
        if (GetAsyncKeyState(VK_F2) & 0x8000)
        {
            ToggleZeroDelay();
            if (zeroDelayEnabled)
                MaintainZeroDelay;
        }
    }
    thread1Running = false;
}

int __stdcall DllMain(HMODULE instance, std::uintptr_t reason, const void* reserved)
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(instance);
        const auto thread1 = CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(CheatThread), instance, 0, nullptr);
        if (thread1) CloseHandle(thread1);
        const auto thread2 = CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(ZeroDelayThread), instance, 0, nullptr);
        if (thread2) CloseHandle(thread2);
        break;
    }

    return TRUE;
}