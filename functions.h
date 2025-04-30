#include "offsets.h"

extern bool infAmmoEnabled;
extern uintptr_t baseAddress;

void MsgBoxAddy(uintptr_t addy)
{
	char szBuffer[1024];
	sprintf_s(szBuffer, "Address: %08X", addy);
	MessageBoxA(NULL, szBuffer, "Address", MB_OK);
}

void showMenu(bool infAmmoEnabled)
{
	std::cout << "loader and cheat made by ZOOMEXX" << "\n" << "\n";
	std::cout << "infinite ammo [F1]";
}

void WaitForKeyRelease(int vkKey)
{
	while (GetAsyncKeyState(vkKey)) Sleep(10);
}

void ToggleInfAmmo()
{
	infAmmoEnabled = !infAmmoEnabled;
	WaitForKeyRelease(VK_F1);
	system("cls");
	showMenu(infAmmoEnabled);
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
			showMenu(infAmmoEnabled);
			break;
		}
	}
}