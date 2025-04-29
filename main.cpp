#define WIN_32_LEAN_AND_MEAN
#include <iostream>
#include <Windows.h>
#include <cstdint>
#include <thread>
#include "functions.h"

DWORD baseAddress = (DWORD)GetModuleHandleA("ac_client.exe");

CEnt* player = NULL;

void CheatThread(HMODULE instance) noexcept
{
    AllocConsole();
    FILE* f = nullptr;
    freopen_s(&f, "CONOUT$", "w", stdout);

    while (!GetAsyncKeyState(VK_F1))
    {

        DWORD* playerBasePtr = (DWORD*)(baseAddress + offset::playerBase);
        if (!playerBasePtr || !*playerBasePtr) continue;

        CEnt* player = (CEnt*)(*playerBasePtr);

        player->clip = 99;

        Sleep(5);
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