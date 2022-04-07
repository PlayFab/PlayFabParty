// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

BOOL
APIENTRY
DllMain(
    HMODULE module,
    DWORD  reason,
    LPVOID reserved
    )
{

    UNREFERENCED_PARAMETER(module);
    UNREFERENCED_PARAMETER(reason);
    UNREFERENCED_PARAMETER(reserved);

    return TRUE;
}

