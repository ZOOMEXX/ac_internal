#include <Windows.h>
#include <vector>

// Created with ReClass.NET 1.2 by KN4CK3R

namespace offset
{
	constexpr uintptr_t playerBase = 0x17E0A8;
}
class CEnt
{
public:
	char pad_0000[320]; //0x0000
	int32_t clip; //0x0140
	char pad_0144[3836]; //0x0144
}; //Size: 0x1040