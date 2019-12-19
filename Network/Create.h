#pragma once

namespace Network
{
	struct PMSG_CHARCREATE
	{
		PBMSG_HEAD h;
		BYTE subcode;
		char Name[10];
		BYTE ClassSkin;
	};

	struct PMSG_GUILDINFOSAVE
	{
		PBMSG_HEAD h;
		BYTE btGuildType;
		char GuildName[8];
		BYTE Mark[32];
	};

	class Create
	{
	public:
		static void initCharacter(PMSG_CHARCREATE* lpMsg, DWORD dwIndex);
		static void initGuild(DWORD dwIndex, PMSG_GUILDINFOSAVE* lpMsg);
	};
}