#include <Windows.h>
#include <vector>

// Created with ReClass.NET 1.2 by KN4CK3R

namespace offset
{
	constexpr uintptr_t playerBase = 0x57E0A8;
}

class CEnt
{
public:
	char pad_0000[93]; //0x0000
	bool touchingGround; //0x005D
	char pad_005E[1]; //0x005E
	bool forceJump; //0x005F
	int8_t crouch; //0x0060
	bool crouchBool; //0x0061
	char pad_0062[1]; //0x0062
	bool forceCrouch; //0x0063
	char pad_0064[28]; //0x0064
	int8_t moveLeft; //0x0080
	int8_t moveRight; //0x0081
	int8_t moveForward; //0x0082
	int8_t moveBackward; //0x0083
	char pad_0084[104]; //0x0084
	int32_t health; //0x00EC
	int32_t armor; //0x00F0
	char pad_00F4[16]; //0x00F4
	bool aliveBool; //0x0104
	char pad_0105[11]; //0x0105
	int32_t shotgunMainAmmo; //0x0110
	char pad_0114[24]; //0x0114
	int32_t pistolClip; //0x012C
	int32_t carbineClip; //0x0130
	int32_t shotgunClip; //0x0134
	int32_t subgunClip; //0x0138
	int32_t sniperClip; //0x013C
	int32_t arClip; //0x0140
	int32_t nadeClip; //0x0144
	int32_t akimboClip; //0x0148
	int32_t knifeDelay; //0x014C
	int32_t pistolDelay; //0x0150
	int32_t carbineDelay; //0x0154
	int32_t shotgunDelay; //0x0158
	int32_t subgunDelay; //0x015C
	int32_t sniperDelay; //0x0160
	int32_t arDelay; //0x0164
	int32_t nadeDelay; //0x0168
	int32_t akimboDelay; //0x016C
	int32_t timesKnifed; //0x0170
	int32_t timesShotPistol; //0x0174
	int32_t timesShotCarbine; //0x0178
	int32_t timesShotShotgun; //0x017C
	int32_t timesShotSubgun; //0x0180
	int32_t timesShotSniper; //0x0184
	int32_t timesShotAr; //0x0188
	int32_t timesNaded; //0x018C
	int32_t timesShotAkimbo; //0x0190
	char pad_0194[112]; //0x0194
	bool forceFire; //0x0204
	char username[16]; //0x0205
	char pad_0215[3642]; //0x0215
}; //Size: 0x104F