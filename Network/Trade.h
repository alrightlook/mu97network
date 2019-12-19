#pragma once

namespace Network
{
	struct PMSG_TRADE_REQUEST
	{
		PBMSG_HEAD h;
		unsigned char NumberH;
		unsigned char NumberL;
	};

	struct PMSG_TRADE_RESPONSE
	{
		PBMSG_HEAD h;
		unsigned char Response;
		unsigned char Id[10];
		unsigned short Level;
		int GuildNumber;
	};

	struct TradeStruct
	{
		unsigned char Enable;
		unsigned char Map;
		unsigned char SafeMap;
		unsigned char SafeX;
		unsigned char SafeY;
	};

	class Trade
	{
	public:
		static bool initComponents();
		static bool initMap(DWORD dwIndex);
		static bool initSafe(DWORD dwIndex);
		static void initRequest(PMSG_TRADE_REQUEST* lpMsg, DWORD dwIndex);
		static void initResponse(PMSG_TRADE_RESPONSE* lpMsg, DWORD dwIndex);
		static void initCancel(DWORD dwIndex);

	public:
		static TradeStruct Struct[15];
	};
}