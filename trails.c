#include <Windows.h>

DWORD WINAPI MainThread(LPVOID lpParam)
{
    /* Add Trails option back to the game menu. */

    *(WORD*)0x6D8F38 = 9;
    memcpy((char*)0x6D8F3A, "FED_TRA\0", 8);
    *(WORD*)0x6D8F4A = 10;
    memcpy((char*)0x6D8F4C, "FED_SUB\0", 8);
    *(WORD*)0x6D8F5C = 11;
    memcpy((char*)0x6D8F5E, "FED_WIS\0", 8);
    *(WORD*)0x6D8F6E = 31;
    memcpy((char*)0x6D8F70, "MAP_LEG\0", 8);
    *(WORD*)0x6D8F80 = 32;
    memcpy((char*)0x6D8F82, "FED_RDR\0", 8);
    *(WORD*)0x6D8F92 = 33;
    memcpy((char*)0x6D8F94, "FED_HUD\0", 8);
    *(WORD*)0x6D8FA4 = 43;
    memcpy((char*)0x6D8FA6, "FED_RES\0", 8);
    *(WORD*)0x6D8FB0 = 40;
    *(WORD*)0x6D8FB4 = 1;
    *(WORD*)0x6D8FB6 = 47;
    memcpy((char*)0x6D8FB8, "FET_DEF\0", 8);
    *(unsigned char*)0x6D8FC1 = 4;
    *(WORD*)0x6D8FC8 = 34;
    memcpy((char*)0x6D8FCA, "FEDS_TB\0", 8);
    *(unsigned char*)0x6D8FD2 = 0;
    *(unsigned char*)0x6D8FD3 = 33;
    *(WORD*)0x6D8FD4 = 320;
    *(WORD*)0x6D8FD6 = 353;
    *(WORD*)0x6D8FD8 = 3;

    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, MainThread, hModule, 0, 0);
        break;

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

