#include "offsets.h"

extern bool infAmmoEnabled;
extern bool zeroDelayEnabled;
extern uintptr_t baseAddress;

void MsgBoxAddy(uintptr_t addy)
{
	char szBuffer[1024];
	sprintf_s(szBuffer, "Address: %08X", addy);
	MessageBoxA(NULL, szBuffer, "Address", MB_OK);
}

void showMenu(bool infAmmoEnabled, bool zeroDelay)
{
	std::cout << "loader and cheat made by ZOOMEXX" << "\n" << "\n";
	std::cout << "infinite ammo [F1]";
	std::cout << "zero delay on weapons [F2]";
}

void WaitForKeyRelease(int vkKey)
{
	while (GetAsyncKeyState(vkKey)) Sleep(10);
}

void ToggleZeroDelay()
{
	zeroDelayEnabled = !zeroDelayEnabled;
	WaitForKeyRelease(VK_F2);
	system("cls");
	showMenu(infAmmoEnabled, zeroDelayEnabled);
}

void MaintainZeroDelay()
{
	while (zeroDelayEnabled && !GetAsyncKeyState(VK_F2))
	{
		Sleep(5);
		uintptr_t* playerBasePtr = (uintptr_t*)(baseAddress + offset::playerBase);
		if (!playerBasePtr || !*playerBasePtr) continue;

		CEnt* player = (CEnt*)(*playerBasePtr);

		player->akimboDelay = 0;
		player->arDelay = 0;
		player->carbineDelay = 0;
		player->knifeDelay = 0;
		player->nadeDelay = 0;
		player->pistolDelay = 0;
		player->shotgunDelay = 0;
		player->sniperDelay = 0;
		player->subgunDelay = 0;
	}
}

void ToggleInfAmmo()
{
	infAmmoEnabled = !infAmmoEnabled;
	WaitForKeyRelease(VK_F1);
	system("cls");
	showMenu(infAmmoEnabled, zeroDelayEnabled);
}

void MaintainInfAmmo()
{
	while (infAmmoEnabled && !GetAsyncKeyState(VK_F1))
	{
		Sleep(5);
		uintptr_t* playerBasePtr = (uintptr_t*)(baseAddress + offset::playerBase);
		if (!playerBasePtr || !*playerBasePtr) continue;

		CEnt* player = (CEnt*)(*playerBasePtr);

		player->akimboClip = 99;
		player->arClip = 99;
		player->carbineClip = 99;
		player->nadeClip = 99;
		player->pistolClip = 99;
		player->shotgunClip = 99;
		player->sniperClip = 99;
		player->subgunClip = 99;
		
		if (GetAsyncKeyState(VK_F1) & 0x8000)
		{
			infAmmoEnabled = false;
			player->akimboClip = 20;
			player->arClip = 20;
			player->carbineClip = 20;
			player->nadeClip = 20;
			player->pistolClip = 20;
			player->shotgunClip = 20;
			player->sniperClip = 20;
			player->subgunClip = 20;
			WaitForKeyRelease(VK_F1);
			system("cls");
			showMenu(infAmmoEnabled, zeroDelayEnabled);
			break;
		}
	}
}