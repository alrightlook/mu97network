#pragma once

#include "Calcule.h"
#include "Map.h"
#include "Drop.h"

namespace Network
{
	struct SettingStruct
	{
		unsigned char Type;
		unsigned long Quantity;
		unsigned char Announce;
		unsigned char Welcome;
		unsigned char Status;
	};

	struct PMSG_IDPASS
	{
		PBMSG_HEAD h;
		unsigned char Sub;
		char Id[10];
		char Pass[10];
		unsigned long Count;
		unsigned char Version[5];
		unsigned char Serial[16];
	};

	struct PMSG_LVPOINTADD
	{
		PBMSG_HEAD h;
		unsigned char Sub;
		unsigned char Type;
	};
	
	class Setting
	{
	public:
		static bool initComponents();
		static void joinServer(PMSG_IDPASS* lpMsg, DWORD dwIndex);
		static void addPoints(PMSG_LVPOINTADD* lpMsg, DWORD dwIndex);

	public:
		static SettingStruct Struct;
	};
}