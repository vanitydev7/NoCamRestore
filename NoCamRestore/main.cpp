#include "main.h"

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
	{
#ifdef HORIZONTAL
		mem::set_uchar(0x5231A6, 0xEB);
#endif

#ifdef VERTICAL
		mem::set_uchar(0x52322D, 0xEB);
		mem::set_uchar(0x5233BA, 0xEB);
#endif
		break;
	}
	case DLL_PROCESS_DETACH:
	{
#ifdef HORIZONTAL
		mem::set_uchar(0x5231A6, 0x75);
#endif

#ifdef VERTICAL
		mem::set_uchar(0x52322D, 0x75);
		mem::set_uchar(0x5233BA, 0x75);
#endif
		break;
	}
	}

	return TRUE;
}