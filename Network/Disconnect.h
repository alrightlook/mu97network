#pragma once

namespace Network
{
	struct PMSG_ACTION
	{
		PBMSG_HEAD h;
		unsigned char Direction;
		unsigned char Action;
		unsigned char TargetH;
		unsigned char TargetL;
	};

	struct DisconnectCheck
	{
		bool Send;
		unsigned long Timer;
		unsigned long Count;
	};

	class Disconnect
	{
	public:
		static void initAction(PMSG_ACTION* lpMsg, DWORD dwIndex);
		static bool checkAction(DWORD dwIndex);

	public:
		static DisconnectCheck Check[1000];
	};
}