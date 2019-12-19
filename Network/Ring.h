#pragma once

namespace Network
{
	struct PMSG_ITEMTHROW
	{
		PBMSG_HEAD h;
		unsigned char X;
		unsigned char Y;
		unsigned char Pos;
	};

	struct PMSG_INVENTORYITEMMOVE
	{
		PBMSG_HEAD h;
		unsigned char Flag;
		unsigned char Num;
		unsigned char Info[4];
		unsigned char FlagEx;
		unsigned char Target;
	};

	class Ring
	{
	public:
		static int initDrop(PMSG_ITEMTHROW* lpMsg, DWORD dwIndex, int szDrop);
		static void initMove(PMSG_INVENTORYITEMMOVE* lpMsg, DWORD dwIndex);
	};
}