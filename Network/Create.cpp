#include "Library.h"

namespace Network
{
	void Create::initCharacter(PMSG_CHARCREATE* lpMsg, DWORD dwIndex)
	{
		if(Function::checkString(lpMsg->Name, Command::Struct[0].Name.Pattern, false))
		{
			ServerCharacterFailSend(dwIndex, lpMsg->Name);
			return;
		}

		ServerCreateCharacter(lpMsg, dwIndex);
	}

	void Create::initGuild(DWORD dwIndex, PMSG_GUILDINFOSAVE* lpMsg)
	{
		if(Function::checkString(lpMsg->GuildName, Command::Struct[0].Name.Pattern, false))
		{
			return;
		}
		
		ServerCreateGuild(dwIndex, lpMsg);
	}
}