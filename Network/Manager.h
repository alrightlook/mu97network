#pragma once

namespace Network
{
	class Manager
	{
	public:
		static void serverProtocol(BYTE btProtocol, LPBYTE lpRecv, DWORD dwLength, DWORD dwIndex, DWORD dwEncrypt, int iSerial);
		static bool userChat(DWORD dwIndex, std::string szMsg);
		static int npcTalk(OBJECTSTRUCT* lpNpc, OBJECTSTRUCT* lpObject);
	
	public:
		static std::string Msg;
	};
}