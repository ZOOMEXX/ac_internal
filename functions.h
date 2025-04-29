#include "offsets.h"


void MsgBoxAddy(uintptr_t addy)
{
    char szBuffer[1024];
    sprintf_s(szBuffer, "Address: %08X", addy);
    MessageBoxA(NULL, szBuffer, "Address", MB_OK);
}